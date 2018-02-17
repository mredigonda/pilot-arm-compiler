/**
 * @file storage.h
 * @brief Implements a Bucket, a data structure to store variable names,
 * assign each of them a number, and query them.
 */
 
#ifndef STORAGE_H
#define STORAGE_H

#include "main.h"

/**
 * @brief A data structure dedicated to maintain a set of names of
 * variables, and associate each one with an integer.
 */
typedef struct _Bucket {
    int sz, nelems;
    char **storage;
} Bucket;

/**
 * @return Returns a new _Bucket.
 */
Bucket create_new_bucket();

/**
 * @param B The bucket to which you want to add an element.
 * @param v The string you want to insert in the Bucket.
 * @return If the element already exists in the Bucket, returns its
 * position. Otherwise, this function inserts it at the end and returns
 * its newly defined position.
 */
int insert_element(Bucket *B, const char *v);

#endif // STORAGE_H
