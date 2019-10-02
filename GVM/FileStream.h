#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

class FileStream
{
public:
	// create a file pointer based on file
	FileStream(const u1* filepath);

	// deallocates file memory
	~FileStream();

	// read a u1 from the stream
	u1 readByte();

	// read a u2 from the stream
	u2 readShort();

	// read a u4 from the stream
	u4 readInt();
private:
	FILE* pFile;
	u8 lenght;
	u8 pos;

};

