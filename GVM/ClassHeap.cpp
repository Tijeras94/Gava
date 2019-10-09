#include "ClassHeap.h"
#include "JavaClass.h"
bool ClassHeap::LoadClass(GString classname, JavaClass* &jclass)
{
	if (!dic.contains(&classname)) {
		jclass = new JavaClass(classname.c_str());
		if (jclass->isLoaded) {
			dic.set(new GString(classname), jclass);
			return true;
		}
		else {
			return false;
		}
	}

	jclass = dic.get(&classname);
	return true;
}

bool ClassHeap::AddClass(JavaClass* pJavaClass)
{
	if (!pJavaClass) return false;
	//std::string name = pJavaClass->GetName();
	char* name = (char*)malloc(120 * sizeof(char));
	pJavaClass->GetClassName(name);

	if (dic.contains(&GString(name))) {
		free(name);
		return false;
	}
	dic.set(new GString(name), pJavaClass); 
	free(name);


	return true;
}