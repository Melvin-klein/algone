#ifndef ALGONE_VECTOR_H
#define ALGONE_VECTOR_H

#include "stdio.h"

#include "math_types.h"

/**
 * @brief Create a new Vector.
 *
 * @param size The number of values inside the vector.
 * @return A pointer to the new vector.
 */
ALG_Vector* ALG_CreateVector(int size);

/**
 * @brief Create a vector from a string with space separator for each values.
 *
 * @param values The string of values.
 * @return The created vector.
 */
ALG_Vector* ALG_CreateVectorFromString(const char values[]);

/**
 * @brief Create a vector by reading a line on .alg file.
 *
 * @param file The file to read.
 * @return A vector with the file's values.
 */
ALG_Vector* ALG_CreateVectorFromFile(FILE *file);

/**
 * @brief Fill all a vector with the value.
 *
 * @param v The vector to fill.
 * @param value The value to use for filling
 */
void ALG_FillVector(ALG_Vector *v, double value);

/**
 * @brief Update a value of coordinates pos inside the vector v.
 *
 * @param v The vector to update.
 * @param pos The position of the update.
 * @param value The value to use for update.
 */
void ALG_SetVectorValueAt(ALG_Vector *v, int pos, double value);

/**
 * @brief Retrieve a value from the vector à position pos.
 * @param v The vector to read.
 * @param pos The position to read.
 * @return Return the value.
 */
double ALG_GetVectorValueAt(const ALG_Vector *v, int pos);

/**
 * @brief Free a vector pointer.
 *
 * @param v The vector to free.
 */
void ALG_DestroyVector(ALG_Vector *v);

#endif //ALGONE_VECTOR_H
