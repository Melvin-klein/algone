#ifndef __ALG_ERROR_H__
#define __ALG_ERROR_H__

#define ALG_MEMORY_ALLOC_ERROR "Could not allocate memory."
#define ALG_ARRAY_OVERFLOW_ERROR "Index of array does not exists."

void ALG_RaiseError(char message[], char file[], int line);
void ALG_AssertMemoryAlloc(void* p, char file[], int line);

#endif
