#ifndef SUBSECTOR
        #define SUBSECTOR
typedef struct {
        pString reference;
        pString path;
        pString value;
        pString owning_sector_id;

        unsigned long datetimeticks_created;
        unsigned long datetimeticks_tocache;
} subsector;
#endif

#ifndef SECTOR
        #define SECTOR
typedef struct {
        pString sector_id; //Session ID in Scorpion terms
        subsector* subsect_heap;
} sector;
#endif

sector sectors[0];
