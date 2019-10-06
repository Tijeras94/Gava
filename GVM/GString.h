#pragma once
class GString {
public:
	GString();
	  
	//copy constructor
	GString(const GString& text);

	GString(const char* text);

	~GString();

	// concat 2 strings
	GString operator + (GString const& obj);

	// check is there equal
	bool operator == (GString const& obj);

	//string lenght
	int lenght();

	//get str pointer
	char* c_str();
private:
	char* data; 

	void copy(const char* text); 
};

