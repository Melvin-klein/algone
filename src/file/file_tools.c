#include "stdlib.h"
#include "stdio.h"

#include "file_tools.h"
#include "../error/error.h"

ALG_FileMetadata* ALG_ReadMetadataFromFile(FILE *file)
{
    rewind(file);

    ALG_FileMetadata* meta = malloc(sizeof(ALG_FileMetadata));

    if (meta == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    ALG_Vector *values = ALG_CreateVectorFromFile(file);

    meta->inputSize = (int) ALG_GetVectorValueAt(values, 0);
    meta->maxLayerSize = (int) ALG_GetVectorValueAt(values, 1);
    meta->nbLayers = (int) ALG_GetVectorValueAt(values, 2);

    return meta;
}