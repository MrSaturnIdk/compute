/// The header file for array helpers

#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define doArithmeticOnArray(arithmetic, list, len, total) \
	do { \
		for (size_t i = 0; i < (len); ++i) { \
			(total) = (total) arithmetic (list)[i]; \
		} \
	} while (0)
int findIndexOfString(const char* restrict array[], size_t len, const char* restrict item);
/// Return is heap
double* getDoubleArray(const char* restrict array[], size_t len);

#endif
