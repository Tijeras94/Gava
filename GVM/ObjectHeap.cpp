#include "ObjectHeap.h"

ObjectHeap::ObjectHeap() :nextObjectPtr(1){

}

Object ObjectHeap::CreateObject(JavaClass* c) {
	Object ret;
	ret.type = 0;
	ret.heapPtr = nextObjectPtr++;

	//TODO: pass class fields GetObjectFieldCount
	Variable* obj = new Variable[1];
	obj[0].ptrValue = (LONG_PTR)c;

	//add object to map
	map.set(ret.heapPtr, obj);

	return ret;
}

Variable* ObjectHeap::GetObjectPointer(Object object)
{
	Variable* obj = NULL;
	if (!map.contains(object.heapPtr))
		return NULL;
	obj = map.get(object.heapPtr);
	return obj;
}
