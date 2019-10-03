#include "FileStream.h"

FileStream::FileStream(const char* filepath)
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

u1 FileStream::peekByte()
{
	u1 ret = readByte();
	fseek(pFile, -1, SEEK_CUR);
	return ret;
}
 
bool FileStream::readBytes(int bytes, u1* &data) {
	data = new u1[bytes];
	if (fread(data, sizeof(u1), bytes, pFile) == bytes) {
		return true;
	}
	return false;
}
 
u2 FileStream::readShort()
{
	u1 byte[2];
	fread(&byte, sizeof(u1), 2, pFile);
	return (byte[0] & 0xFF) << 8 | (byte[1] & 0xFF);
}

u2 FileStream::peekShort()
{
	u2 ret = readShort();
	fseek(pFile, -2, SEEK_CUR);
	return ret;
}

u4 FileStream::readInt()
{
	u2 f = readShort();
	u2 s = readShort();
	return (f & 0xFFFF) << 16 | (s & 0xFFFF);
}

u4 FileStream::peekInt()
{
	u4 ret = readInt();
	fseek(pFile, -4, SEEK_CUR);
	return ret;
}