#include "server.h"

void get_length(const char* word){
    /* string must be null terminated */
    const char *p = word;
    int length=0;
    for(;*p!='\0';p++);
    length = p-word;    
    printf("Length of %s: %d",word,length);
}

