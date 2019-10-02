#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

class FileStream
{
public:
	FileStream(const u1* filepath);
	~FileStream();

	u1 readByte();
	u2 readShort();
	u4 readInt();


private:
	FILE* pFile;
	u8 lenght;
	u8 pos;

};

