#ifndef ALGONE_FILE_METADATA_H
#define ALGONE_FILE_METADATA_H

typedef struct {
    int inputSize;
    int maxLayerSize;
    int nbLayers;
} ALG_FileMetadata;

void ALG_DestroyFileMetadata(ALG_FileMetadata *m);

#endif //ALGONE_FILE_METADATA_H
