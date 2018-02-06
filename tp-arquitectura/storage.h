#ifndef STORAGE_H
#define STORAGE_H

#include "main.h"

/**
 * @brief Una estructura dedicada a mantener un conjunto de nombres
 * de variables, y asociar cada una a un entero.
 */
typedef struct _Bucket {
    int sz, nelems;
    char **storage;
} Bucket;

/**
 * @return Retorna un nuevo _Bucket inicializado con 0 elementos, y
 * 256 de espacio.
 */
Bucket create_new_bucket();

/**
 * @param B El bucket al cual se le quiere agregar el elemento.
 * @param v La cadena de texto que se quiere meter en el _Bucket.
 * Introduce el elemento en el bucket, si es que no existe todavía.
 */
void insert_element(Bucket *B, const char *v);

#endif // STORAGE_H
