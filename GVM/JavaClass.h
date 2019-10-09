#pragma once
#include "types.h"
#include "FileStream.h"
#include "CStream.h"
#include "ObjectHeap.h"
#include "ClassHeap.h"

class JavaClass : ClassFile
{
public:
	bool isLoaded;
	ObjectHeap* heap;
	ClassHeap* loader;

public:
	JavaClass(const char* filename);
	CStream GetStreamConstant(int index);
	cp_info GetConstant(int index);

	method_info GetMethod(const char* name, const char* signature);
	Code_attribute getCodeFromMethod(method_info info);
	 
	bool GetUtf8String(cp_info sc, char* name);
	
	bool GetClassName(char* name);
	bool GetSuperClassName(char* name);
	JavaClass* GetSuperClass();

	static bool Load(const char* filename, JavaClass& cf);
};

