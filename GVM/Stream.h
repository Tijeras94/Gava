#pragma once
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

class Stream
{
public:
	// 
	Stream();

	// create a file pointer based on file
	Stream(const u1* data, u4 size);

	// deallocates file memory
	~Stream();

	// read a u1 from the stream
	u1 readByte();
	u1 peekByte();

	// read bytes from the stream, returns true if success else false, must be a valid array
	bool readBytes(int bytes, u1* data); 

	// read a u2 from the stream
	u2 readShort();
	i2 readSignedShort();

	u2 peekShort();
	i2 peekSignedShort();

	// read a u4 from the stream
	u4 readInt();
	u4 peekInt();

	void seekoffset(i4 pos);
	void setPos(u8 pos);


	bool eof();

protected:
	//array of bytes of the data
	u1* data;
	//size of the data
	u8 lenght;
	// used to keep track of the cursor 
	u8 pos;

};

