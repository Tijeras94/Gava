#include "CStream.h"
#include <memory>

CStream::CStream(cp_info ci) 
{
	int size = 0;
	switch (ci.tag)
	{
	case CONSTANT_Utf8:
	{
		int sl = (int)Stream(ci.info, 2).peekShort(); //get the lenght 
		size = sl + 2;
		break;
	}
	case CONSTANT_String:
		size = sizeof(struct CONSTANT_String_info) - 2;
		break;
	case CONSTANT_Integer:
		size = sizeof(u4);
		break;
	case CONSTANT_NameAndType:
		size = sizeof(struct CONSTANT_NameAndType_info) - 2;
		break;
	case CONSTANT_Class:
		size = sizeof(struct CONSTANT_Class_info) - 2;
		break;
	case CONSTANT_Methodref:
		size = sizeof(struct CONSTANT_Methodref_info) - 2;
		break;
	default:
		printf("CStream - constant tag(%i) not supported :( \n", ci.tag);
		//exit(EXIT_FAILURE); 
		break;
	}
	this->tag = ci.tag;
	if (size > 0) {
		this->data = new u1[size];
		this->pos = 0;
		this->lenght = size;
		memcpy(this->data, ci.info, size);
	} 
}