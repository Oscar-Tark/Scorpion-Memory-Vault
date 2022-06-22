#ifndef PSTRING
        #define PSTRING
        typedef char* pString;

        //Allocates a new pString to the heap with a set null byte
        pString newpString(void){
                pString p_allocated = malloc(1);
                memset(p_allocated, 0, 1);
                return p_allocated;
        }

        pString setpString(pString p_allocated, const char* string){
                int size = strlen(string);

                p_allocated = (pString)realloc(p_allocated, size);
                strncpy(p_allocated, string, size);
                return p_allocated;
        }

        void freepString(pString p_allocated){
                if(p_allocated != NULL)
                        free(p_allocated);
        }
#endif
