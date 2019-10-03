#include "FileStream.h"
#include <stdio.h>

FileStream::FileStream(const char* filepath) 
{ 
	FILE* file = fopen(filepath, "rb"); 
	if (file != NULL)
	{
		// obtain file size:
		fseek(file, 0, SEEK_END); // move cursor to the end to calculate the size
		this->lenght = ftell(file); // get the position(size) of the file at the current cursor pos
		this->pos = 0; // you need to initialize field from the Stream class
		rewind(file);
		this->data = new u1[this->lenght];
		fread(this->data, sizeof(char), this->lenght, file);
		fclose(file);
	}
}