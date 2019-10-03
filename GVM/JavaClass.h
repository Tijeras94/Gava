#pragma once
#include "types.h"
#include "FileStream.h"

class JavaClass : ClassFile
{
public:
	JavaClass(const char* filename);
	cp_info GetConstant(int index);

	method_info GetMethod(const char* name, const char* signature);
	Code_attribute getCodeFromMethod(method_info info);
	bool GetUtf8String(cp_info sc, char* name);
	
	bool GetClassName(char* name);
	bool GetSuperClassName(char* name);
	JavaClass* GetSuperClass();

	static bool Load(const char* filename, JavaClass& cf);
};

