#include "Stream.h" 
#include <memory>

Stream::Stream()
{
	this->data = nullptr;
	this->pos = 0;
	this->lenght = 0;
}

Stream::Stream(const u1* data, u4 size)
{
	this->data = new u1[size];
	this->pos = 0;
	this->lenght = size;
	memcpy(this->data, data, size);
}

Stream::~Stream()
{
	delete[] this->data;
}

u1 Stream::readByte()
{
	u1* curr = pos + this->data;
	u1 byte;
	memcpy(&byte, curr, 1);
	pos++;
	return byte;
}

bool Stream::eof()
{
	return (pos > lenght);
}

u1 Stream::peekByte()
{ 
	u1 ret = readByte();
	pos -= 1;
	return ret;
}

bool Stream::readBytes(int bytes, u1*& data) {
	u1* curr = pos + this->data;
	data = new u1[bytes]; 
	memcpy(data, curr, bytes); 
	pos += bytes;
	return true;
}

u2 Stream::readShort()
{
	u1* curr = pos + this->data;
	u1 byte[2]; 
	memcpy(byte, curr, 2);
	pos += 2;
	return (byte[0] & 0xFF) << 8 | (byte[1] & 0xFF);
}

u2 Stream::peekShort()
{
	u2 ret = readShort();
	pos -= 2;
	return ret;
}

u4 Stream::readInt()
{
	u2 f = readShort();
	u2 s = readShort();
	return (f & 0xFFFF) << 16 | (s & 0xFFFF);
}

u4 Stream::peekInt()
{
	u4 ret = readInt();
	pos -= 4;
	return ret;
}