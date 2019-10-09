#pragma once

//#include "JavaClass.h" 
#include "Dictionary.h"
#include "GString.h"

class JavaClass;
class ClassHeap
{
public:  
	bool LoadClass(GString classname, JavaClass* &jclass);
	bool AddClass(JavaClass* pJavaClass);

private:
	Dictionary<GString*, JavaClass*> dic;

};

