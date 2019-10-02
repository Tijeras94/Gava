#include "FileStream.h"




FileStream::FileStream(const u1* filepath)
{
	pos = 0;
	pFile = fopen(filepath, "r");
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
	
}

u2 FileStream::readShort()
{

}

u4 FileStream::readInt()
{

}