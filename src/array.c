/**
 * Some helpers for arrays
 * I don't wanna clog my main file
 */

#include "array.h"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int findIndexOfString(const char* restrict array[], size_t len, const char* restrict item) {
	assert(item);
	for (size_t i = 0; i < len; ++i) {
		assert(array[i]);
		if (!strcmp(array[i], item)) {
			return (int)i;
		}
	}
	return -1;
}
double* getDoubleArray(const char* restrict array[], size_t len) {
	double* arr = calloc(len, sizeof(double));
	if (!arr) {
		return NULL;
	}
	for (size_t i = 0; i < len; ++i) {
		assert(array[i]);
		arr[i] = atof(array[i]);
	}
	return arr;
}
