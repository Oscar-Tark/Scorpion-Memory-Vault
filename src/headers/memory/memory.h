#include "types.h"
#include <string.h>

int alloc(pString session_sector_id, pString reference, pString value){

	//Allocate a new sector
	sector* sect;
	if((sect = malloc(sizeof(sector))) == NULL)
		return FALSE;

	//Set heap values to nullbyte
	memset(sect->sector_id, 0, sizeof(pString));

	//Set values to the newely created heap alloc
	memcpy(sect->sector_id, session_sector_id, sizeof(session_sector_id));

	return TRUE;
}

char* find(){

}

short del(){

}
