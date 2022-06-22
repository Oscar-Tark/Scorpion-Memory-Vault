#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef FATAL
	#define FATAL
	void fatal(char* message, int exitcode)
	{
        	char buffer[2048];
	        strcpy(buffer, "ERROR: ");
        	strcat(buffer, message);
	        perror(buffer);
        	exit(exitcode);
	}
#endif
