#include <stdio.h>
#include <assert.h>
#include <memory>
#include "types.h"

//#include "FileStream.h"
#include "JavaClass.h"
#include "Stream.h"

int main()
{
	JavaClass jclass("Hello");

	//char name[100];
	method_info info =  jclass.GetMethod("main", "([Ljava/lang/String;)V");
	for (int i = 0; i < info.attributes_count; i++)
	{
		char name[100];
		jclass.GetUtf8String(jclass.GetConstant(info.attributes[i].attribute_name_index), name);
		if (strcmp(name, "Code") == 0){
			
			Code_attribute ca; 
			ca.attribute_name_index = info.attributes[i].attribute_name_index;
			ca.attribute_length = info.attributes[i].attribute_length;
			Stream code(info.attributes[i].info, info.attributes[i].attribute_length);
			ca.max_stack = code.readShort();
			ca.max_locals = code.readShort();
			ca.code_length = code.readInt();
			ca.code = new u1[ca.code_length];
			code.readBytes(ca.code_length, ca.code);
			//ca.code[code_length];



			printf("Hello World!\n");
		}
	}
}
