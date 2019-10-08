#include "JavaClass.h"
#include "Stream.h"
#include <memory>

JavaClass::JavaClass(const char* filename)
{
	char fp[120];
	strcpy(fp, "sdk/");
	strcat(fp, filename);
	strcat(fp, ".class");

	this->isLoaded = true;

	if (!JavaClass::Load(fp, *this))
	{
		printf("Unable to load class \"%s\"\n", filename);
		this->isLoaded = false;
	}

}
 
bool JavaClass::GetUtf8String(cp_info sc,  char* name)
{
	if (sc.tag == CONSTANT_Utf8) {
		//get the name utf8
		auto str_len = getu2(sc.info) + 1; // add the null character to string
		memcpy(name, sc.info + 2, str_len);
		name[str_len - 1] = 0; 
		return true;
	}
	return false;
}

bool JavaClass::GetClassName(char* name)
{
	auto sc = GetConstant(this->this_class);
	if (sc.tag == CONSTANT_Class) {
		auto name_index = getu2(sc.info);
		//get the name utf8
		sc = GetConstant(name_index);
		if (GetUtf8String(sc, name)) {
			return true;
		}
	}

	return false;
}
  
method_info JavaClass::GetMethod(const char* name, const char* signature)
{
	JavaClass* curr = this;
	while (curr != nullptr)
	{
		for (int i = 0; i < this->methods_count; i++)
		{
			char tmp[120];
			GetUtf8String(GetConstant(this->methods[i].name_index), tmp);
			if (strcmp(tmp, name) == 0) {
				GetUtf8String(GetConstant(this->methods[i].descriptor_index), tmp);
				if (strcmp(tmp, signature) == 0) {
					return this->methods[i];
				}
			}
		}

		if (curr != nullptr)
			curr = curr->GetSuperClass();// go to his super class to find the method
	}
	method_info i;
	i.name_index = -1;
	return i;
}

Code_attribute JavaClass::getCodeFromMethod(method_info info)
{
	Code_attribute ca;
	ca.attribute_name_index = -1; // if not found set index to an invalid entry

	for (int i = 0; i < info.attributes_count; i++)
	{
		char name[100];
		this->GetUtf8String(this->GetConstant(info.attributes[i].attribute_name_index), name);
		if (strcmp(name, "Code") == 0) {

			ca.attribute_name_index = info.attributes[i].attribute_name_index;
			ca.attribute_length = info.attributes[i].attribute_length;
			Stream code(info.attributes[i].info, info.attributes[i].attribute_length);
			ca.max_stack = code.readShort();
			ca.max_locals = code.readShort();
			ca.code_length = code.readInt();
			ca.code = new u1[ca.code_length];
			code.readBytes(ca.code_length, ca.code);
			ca.exception_table_length = code.readShort();
			ca.exception_table = new exception_table[ca.exception_table_length];
			for (int i = 0; i < ca.exception_table_length; i++)
			{
				ca.exception_table[i].start_pc = code.readShort();
				ca.exception_table[i].end_pc = code.readShort();
				ca.exception_table[i].handler_pc = code.readShort();
				ca.exception_table[i].catch_type = code.readShort();
			}
			ca.attributes_count = code.readShort();
			ca.attributes = new attribute_info[ca.attributes_count];
			for (int i = 0; i < ca.attributes_count; i++)
			{
				ca.attributes[i].attribute_name_index = code.readShort();
				ca.attributes[i].attribute_length = code.readShort();
				//delete mory
				code.readBytes(ca.attributes[i].attribute_length, ca.attributes[i].info = new u1[ca.attributes[i].attribute_length]);
			}
		}
	}

	return ca;
}

bool JavaClass::GetSuperClassName(char*name)
{
	auto sc = GetConstant(super_class);
	if (sc.tag == CONSTANT_Class) {
		auto name_index = getu2(sc.info);
		//get the name utf8
		sc = GetConstant(name_index);
		if (GetUtf8String(sc, name)) {
			return true;
		}
	} 

	return false;
}

CStream JavaClass::GetStreamConstant(int index)
{
	return CStream(GetConstant(index));
}

cp_info JavaClass::GetConstant(int index)
{
	if (index < this->constant_pool_count) {
		return this->constant_pool[index - 1];
	}

	cp_info sc;
	sc.tag = 0; 
	return sc;
}


JavaClass* JavaClass::GetSuperClass()
{
	char name[120];
	memset(name,0, 120);
	if (GetSuperClassName(name))
	{ 
		return new JavaClass(name);
	} 
	return nullptr;
}

bool JavaClass::Load(const char* filename, JavaClass& cf)
{
	FileStream reader(filename);
	if (!reader.Success) return false;

	cf.magic = reader.readInt();
	cf.minor_version = reader.readShort();
	cf.major_version = reader.readShort();
	cf.constant_pool_count = reader.readShort();
	cf.constant_pool = new cp_info[cf.constant_pool_count];
	int cindex = 0;
	for (int i = 0; cindex < cf.constant_pool_count - 1; i++)
	{
		
		cf.constant_pool[cindex].tag = reader.readByte();
		printf("tag index %i: %i\n", cindex+1, cf.constant_pool[cindex].tag);
		int size = 0;
		//iin order to get the right bytes for the info, you subtract the byte for the tag and the byte that the struct is holding
		switch (cf.constant_pool[cindex].tag)
		{
		case CONSTANT_Utf8:
		{
			u2 length = reader.peekShort(); //get the lenght
			size = length + 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			//read the first short containing the lenght of string and get the string bytes
			reader.readBytes(length + 2, cf.constant_pool[cindex].info);
			break;
		}
		case CONSTANT_String:
			size = sizeof(struct CONSTANT_String_info) - 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);
			break;
		case CONSTANT_Integer:
			size = sizeof(u4);
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);
			break;
		case CONSTANT_Double:
			size = 8;// sizeof(struct CONSTANT_Double_info) - 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);

			cindex++; // add extra slot
			cf.constant_pool[cindex].tag = -1;
			cf.constant_pool[cindex].info = new u1[1];
			break;
		case CONSTANT_NameAndType:
			size = sizeof(struct CONSTANT_NameAndType_info) - 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);
			break;
		case CONSTANT_Class:
			size = sizeof(struct CONSTANT_Class_info) - 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);
			break;
		case CONSTANT_Methodref:
			size = sizeof(struct CONSTANT_Methodref_info) - 2;
			cf.constant_pool[cindex].info = new u1[size]; // make sure to free this data later on
			reader.readBytes(size, cf.constant_pool[cindex].info);
			break;
		default:
			printf("constant tag(%i) not supported :( \n", cf.constant_pool[cindex].tag);
			//exit(EXIT_FAILURE);
			return false;
			break;
		}

		cindex++;
	}
	cf.access_flags = reader.readShort();
	cf.this_class = reader.readShort();
	cf.super_class = reader.readShort();
	cf.interfaces_count = reader.readShort();
	cf.interfaces = new u2[cf.interfaces_count];
	for (int i = 0; i < cf.interfaces_count; i++)
	{
		cf.interfaces[i] = reader.readShort();
	}
	cf.fields_count = reader.readShort();;
	cf.fields = new field_info[cf.fields_count];
	for (int i = 0; i < cf.fields_count; i++)
	{
		cf.fields[i].access_flags = reader.readShort();
		cf.fields[i].name_index = reader.readShort();
		cf.fields[i].descriptor_index = reader.readShort();
		cf.fields[i].attributes_count = reader.readShort();
		cf.fields[i].attributes = new attribute_info[cf.fields[i].attributes_count];
		for (int q = 0; q < cf.fields[i].attributes_count; q++)
		{
			cf.fields[i].attributes[q].attribute_name_index = reader.readShort();
			cf.fields[i].attributes[q].attribute_length = reader.readInt();
			reader.readBytes(cf.fields[i].attributes[q].attribute_length, cf.fields[i].attributes[q].info);
		}
	}
	cf.methods_count = reader.readShort();
	cf.methods = new method_info[cf.methods_count];
	for (int i = 0; i < cf.methods_count; i++)
	{
		cf.methods[i].access_flags = reader.readShort();
		cf.methods[i].name_index = reader.readShort();
		cf.methods[i].descriptor_index = reader.readShort();
		cf.methods[i].attributes_count = reader.readShort();
		cf.methods[i].attributes = new attribute_info[cf.methods[i].attributes_count];
		for (int q = 0; q < cf.methods[i].attributes_count; q++)
		{
			cf.methods[i].attributes[q].attribute_name_index = reader.readShort();
			cf.methods[i].attributes[q].attribute_length = reader.readInt();
			//make sure to delete data
			reader.readBytes(cf.methods[i].attributes[q].attribute_length, cf.methods[i].attributes[q].info = new u1[cf.methods[i].attributes[q].attribute_length]);
		}
	}
	cf.attributes_count = reader.readShort();
	cf.attributes = new attribute_info[cf.attributes_count];
	for (int q = 0; q < cf.attributes_count; q++)
	{
		cf.attributes[q].attribute_name_index = reader.readShort();
		cf.attributes[q].attribute_length = reader.readInt();
		//make sure to delete data
		reader.readBytes(cf.attributes[q].attribute_length, cf.attributes[q].info = new u1[cf.attributes[q].attribute_length]);
	}
	return true;
}