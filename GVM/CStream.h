#pragma once
#include "Stream.h"
#include "types.h"
class CStream :
	public Stream
{
public:
	CStream(cp_info ci); 
	int tag;
};

