#pragma once
#include "types.h"
#include "FileStream.h"

class JavaClass : ClassFile
{
public:
	JavaClass(const u1* filename);
	cp_info GetConstant(int index);

	method_info GetMethod(const char* name, const char* signature);
	bool GetUtf8String(cp_info sc, char* name);
	
	bool GetClassName(char* name);
	bool GetSuperClassName(char* name);
	JavaClass* GetSuperClass();

	static bool Load(const u1* filename, JavaClass& cf);
};

