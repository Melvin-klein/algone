#include "stdlib.h"
#include "stdio.h"

#include "./error.h"

void ALG_RaiseError(char message[], char file[], int line)
{
    printf("!!! Error %s:%d <%s>\n", file, line, message);
    exit(0);
}

void ALG_AssertMemoryAlloc(void* p, char file[], int line)
{
    if (p == NULL) {
        ALG_RaiseError(ALG_MEMORY_ALLOC_ERROR, file, line);
    }
}
