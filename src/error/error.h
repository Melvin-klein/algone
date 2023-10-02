#ifndef ALGONE_ERROR_H
#define ALGONE_ERROR_H

#include "stdbool.h"
#include "string.h"

/**
 * @brief Describe all algone error.
 */
typedef enum {
    ALG_OK = 0,
    ALG_MATH_ERROR,
    ALG_MEMORY_ALLOCATION_ERROR,
    ALG_INCOMPATIBLE_ERROR,
    ALG_FILE_ERROR
} ALG_ErrorCode;


/**
 * @brief Structure of Algone's errors.
 *
 * @var message Own the error message as a string.
 * @var code Own the error code from ALG_ErrorCode enum.
 * @var len The size of message.
 * @var file The file name where error occurs.
 * @var line The line where error occurs.
 * @var hasError Is set to true if a function raise an error.
 */
typedef struct {
    char *message;
    ALG_ErrorCode code;
    size_t len;
    char *file;
    int line;
    bool *hasError;
} ALG_Error;

/**
 * @brief Return the error global variable.
 *
 * @return The error struct.
 */
ALG_Error* ALG_GetStaticErrBuf(void);

/**
 * @brief Set an error in the global error variable.
 *
 * @param errorCode The error code from the ALG_ErrorCode enum.
 * @param errorMessage The explicit error message that can be printed by ALG_PrintError().
 * @param file The file where the error occurs.
 * @param line The line where the error occurs.
 */
void ALG_SetError(int errorCode, const char *errorMessage, char *file, int line);

/**
 * @brief Returns the global error struct.
 *
 * @return See brief.
 */
ALG_Error* ALG_GetError();

/**
 * @brief Returns true if ALG_SetError has been called else false.
 *
 * @return See brief;
 */
bool ALG_HasError();

/**
 * @brief Print the error message from the global error struct.
 */
void ALG_PrintError();

#endif
