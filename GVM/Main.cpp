#include <stdio.h>
#include <assert.h>
#include "types.h"

#include "FileStream.h"


int main()
{
	FileStream s("sdk/Hello.class");
	u4 sig = s.readInt();


	printf("Hello World!\n");
}
