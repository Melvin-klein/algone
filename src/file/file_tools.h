#ifndef ALGONE_FILE_TOOLS_H
#define ALGONE_FILE_TOOLS_H

#include "stdio.h"

#include "FileMetadata.h"
#include "../math/vector.h"

/**
 * @brief Retrieve Metadata from a .alg file.
 *
 * @param filename The file to parse.
 */
ALG_FileMetadata* ALG_ReadMetadataFromFile(FILE *file);

/**
 * @brief
 *
 * @param file
 * @return
 */
ALG_Vector *ALG_ReadLayerFromFile(FILE *file);

#endif //ALGONE_FILE_TOOLS_H
