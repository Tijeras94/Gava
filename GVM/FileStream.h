#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "Stream.h"

class FileStream : public Stream
{
public:
	// create a file pointer based on file
	FileStream(const char* filepath); 
private:  
};

