#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#include "vector.h"
#include "../../../../Downloads/algone-dev/src/error/error.h"

ALG_Vector* ALG_CreateVector(int size)
{
    ALG_Vector *v = malloc(sizeof(ALG_Vector));

    if (v == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    v->values = malloc(sizeof(*v->values) * size);

    if (v->values == NULL) {
        ALG_SetError(ALG_MEMORY_ALLOCATION_ERROR, "Could not allocate memory", __FILE__, __LINE__);

        return NULL;
    }

    v->size = size;

    return v;
}

ALG_Vector* ALG_CreateVectorFromString(const char values[])
{
    // Count how many values there is in the line
    // by counting whitespace characters + 1
    int i, count;
    for (i = 0, count = 1; values[i]; i++)
        count += (values[i] == ' ');

    ALG_Vector *v = ALG_CreateVector(count);
    char *s = malloc(sizeof(char) * strlen(values));

    // We create a copy of `values` because `strtok` don't handle const string.
    // We need a const string to use literal string as parameter.
    strcpy(s, values);

    char* token = strtok(s, " ");;

    for (i = 0; i < count; i++) {
        ALG_SetVectorValueAt(v, i, atof(token));
        token = strtok(NULL, " ");
    }

    free(s);

    return v;
}

ALG_Vector* ALG_CreateVectorFromFile(FILE *file)
{
    char* line = NULL;
    size_t len = 0;

    if (getline(&line, &len, file) == -1) {
        return NULL;
    }

    ALG_Vector *values = ALG_CreateVectorFromString(line);

    if (line != NULL) {
        free(line);
    }

    return values;
}

void ALG_FillVector(ALG_Vector *v, double value)
{
    for (int i = 0; i < v->size; i++) {
        v->values[i] = value;
    }
}

void ALG_SetVectorValueAt(ALG_Vector *v, int pos, double value)
{
    v->values[pos] = value;
}

double ALG_GetVectorValueAt(const ALG_Vector *v, int pos)
{
    return v->values[pos];
}

void ALG_DestroyVector(ALG_Vector *v)
{
    free(v->values);
    free(v);
}