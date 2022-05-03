#include "types.h"

typedef struct {
	pString reference;
	pString path;
	pString value;
	pString owner_hash;

	unsigned long datetimeticks_created;
	unsigned long datetimeticks_tocache;
} variable;

typedef struct {

} owner;

struct memory{
	owner* owners[0];
        variable* variables[0];
};

