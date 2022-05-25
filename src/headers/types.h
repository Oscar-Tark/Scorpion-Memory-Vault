#ifndef TYPES
	#define TRUE 1
	#define FALSE 0
#endif

#ifndef PSTRING
	#define PSTRING
	typedef char* pString;
#endif

#ifndef VARIABLE
	#define VARIABLE
typedef struct {
        pString reference;
        pString path;
        pString value;
        pString owner_hash;
        unsigned long datetimeticks_created;
        unsigned long datetimeticks_tocache;
} variable;
#endif

#ifndef OWNER
	#define OWNER
typedef struct {
} owner;
#endif

#ifndef MEMORY
	#define MEMORY
struct memory{
        owner* owners[0];
        variable* variables[0];
};
#endif
