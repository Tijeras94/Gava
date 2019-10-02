#include "FileStream.h"




FileStream::FileStream(const u1* filepath)
{
	pos = 0;
	pFile = fopen(filepath, "rb");
	if (pFile != NULL)
	{
		// obtain file size:
		fseek(pFile, 0, SEEK_END);
		lenght = ftell(pFile);
		rewind(pFile);
	}
	else {
		pFile = NULL;
		lenght  = 0;
	}
}

FileStream::~FileStream()
{
	fclose(pFile);
}

u1 FileStream::readByte()
{
	u1 byte;
	fread(&byte, sizeof(u1), 1, pFile);
	return byte;
}

//get short big indian
u2 FileStream::readShort()
{
	u1 byte[2];
	fread(&byte, sizeof(u1), 2, pFile);
	return (byte[0] & 0xFF) << 8 | (byte[1] & 0xFF);
}

u4 FileStream::readInt()
{
	u2 f = readShort();
	u2 s = readShort();
	return (f & 0xFFFF) << 16 | (s & 0xFFFF);
}