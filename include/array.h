/** The header file for array helpers */

#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

#define doArithmeticOnArray(arithmetic, list, len, total) \
	do { \
		size_t i = 0; \
		for (i = 0; i < (len); ++i) { \
			(total) = (total) arithmetic (list)[i]; \
		} \
	} while (0)
int findIndexOfString(const char* array[], size_t len, const char* item);
/** Return is heap */
double* getDoubleArray(const char* array[], size_t len);

#endif
