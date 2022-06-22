#include <stdarg.h>
#include <stdio.h>

void getArgvVariadic(int num, char** argv, int argc, char** out, ...){

	va_list vaPtr;
	va_start(vaPtr, out);

	char* temp;
	memset(temp, '\0', 0);

	//Find args
	for(int j = 0; j < num; j++){
		printf("Got argument %d: \n", j);
		temp = (char*)va_arg(vaPtr, char*);
		printf("%s\n", temp);

		//Find argument in argv
		for(int i = 0; i < argc; i++){

			printf("Debug: %s\n", argv[i]);

			if(argv[i] == temp){
				printf("In: %s\n", temp);
				out[j] = (char*)va_arg(vaPtr+1, char*);
				printf("Value: %s\n", out[j]);
			}
		}
	}
	va_end(vaPtr);
	return;
}
