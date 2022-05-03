#include <stdlib.h>

#define T_NULL (void*)0;
#define S_NULL '\0';

//Partially managed C string
#ifndef PSTRING
	#define PSTRING
	typedef struct {
		//Heap allocated value
		char* value;
	} pString;
#endif

pString* pStringNew(){
	return (pString*)malloc(sizeof(pString));
}

void pStringDelete(pString* pstring){
	free((void*)pstring);
};
