#pragma once
#include "types.h"
#include "Dictionary.h" 

class JavaClass;
class ObjectHeap
{
public:
	ObjectHeap();
	Object CreateObject(JavaClass* c);
	Variable* GetObjectPointer(Object object);
private:
	int nextObjectPtr;
	Dictionary<LONG_PTR, Variable*> map;
};

