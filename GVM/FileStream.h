#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

class FileStream
{
public:
	// create a file pointer based on file
	FileStream(const char* filepath);

	// deallocates file memory
	~FileStream();

	// read a u1 from the stream
	u1 readByte(); 
	u1 peekByte();

	// read bytes from the stream, returns true if success else false
	bool readBytes(int bytes, u1* &data);

	// read a u2 from the stream
	u2 readShort();
	u2 peekShort();

	// read a u4 from the stream
	u4 readInt();
	u4 peekInt();
private:
	FILE* pFile;
	u8 lenght;
	u8 pos;

};

