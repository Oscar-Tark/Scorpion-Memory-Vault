#include <string.h>
#include "pString.h"

#ifndef TYPES
	#define TRUE 1
	#define FALSE 0
#endif

#ifndef OPCODEMEM
	#define OPCODEMEM
	char opcode_add		= 0x01;
	char opcode_find	= 0x02;
	char opcode_delete	= 0x03;
#endif
