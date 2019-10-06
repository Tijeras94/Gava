#include "GString.h"
#include <memory>

GString::GString() {
	data = (char*)malloc(1);
	if (data)
		data[0] = 0; //null
}

GString::GString(const char* text) {
	copy(text);
}

GString::~GString() {
	free( data);
}

//copy constructor
GString::GString(const GString& text) {
	copy(text.data);
}

// concat 2 strings
GString GString::operator + (GString const& obj) {
	char* data = (char*)malloc(strlen(obj.data) + strlen(this->data) + 1);
	strcpy(data, this->data);
	strcat(data, obj.data);
	GString ret = GString(data);
	free( data);
	free(this->data);
	return ret;
}

// check is there equal
bool GString::operator == (GString const& obj) {

	return strcmp(this->data, obj.data) == 0;
}

//string lenght
int GString::lenght() {
	return (int)strlen(data);
}

//get str pointer
char* GString::c_str() {
	return data;
}


void GString::copy(const char* text) {
	int slen = (int)strlen(text);
	data = (char*)malloc((int)slen + 1);
	if (data)
		strcpy(data, text);
}