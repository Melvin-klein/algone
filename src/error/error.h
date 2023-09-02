#ifndef __ALG_ERROR_H__
#define __ALG_ERROR_H__

#define ALG_MEMORY_ALLOC_ERROR "Could not allocate memory."
#define ALG_ARRAY_OVERFLOW_ERROR "Index of array does not exists."

/**
 * @brief Print an error into the console.
 *
 * @param message The message to print.
 * @param file The name of the file which thrown the error.
 * @param line The line where the error is thrown.
 */
void ALG_RaiseError(char message[], char file[], int line);

/**
 * @brief Check if manual memory allocation has worked.
 *
 * @param p The pointer to check.
 * @param file The name of the file which check the pointer.
 * @param line The line where the pointer is checked.
 */
void ALG_AssertMemoryAlloc(void* p, char file[], int line);

#endif
