#include "stdlib.h"

#include "FileMetadata.h"

void ALG_DestroyFileMetadata(ALG_FileMetadata *m)
{
    free(m);
}