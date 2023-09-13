#include "stdlib.h"
#include "stdio.h"

#include "./error.h"

ALG_Error* ALG_GetStaticErrBuf(void)
{
    static ALG_Error ALG_global_error;
    static char ALG_global_error_str[128];
    static bool ALG_has_error = false;
    ALG_global_error.message = ALG_global_error_str;
    ALG_global_error.len = sizeof(ALG_global_error_str);
    ALG_global_error.hasError = &ALG_has_error;
    return &ALG_global_error;
}

void ALG_SetError(int errorCode, const char *errorMessage, char *file, int line)
{
    ALG_Error *error = ALG_GetStaticErrBuf();

    error->code = errorCode;
    strcpy(error->message, errorMessage);
    error->len = strlen(errorMessage);
    error->file = file;
    error->line = line;

    *error->hasError = true;
}

ALG_Error* ALG_GetError()
{
    return ALG_GetStaticErrBuf();
}

bool ALG_HasError()
{
    ALG_Error *error = ALG_GetStaticErrBuf();

    return *error->hasError;
}

void ALG_PrintError()
{
    if (ALG_HasError()) {
        ALG_Error *error = ALG_GetStaticErrBuf();

        printf("!!! [ERROR] %s:%d <%s>\n", error->file, error->line, error->message);
    }
}