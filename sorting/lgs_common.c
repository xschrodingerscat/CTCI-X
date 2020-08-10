

#include "lgs_common.h"


void 
lgs_copy(void *dst, void *src, int size)
{
	memcpy(dst, src, size);
}

void
lgs_free(void *p)
{
	free(p);
}

void *
lgs_malloc(int size) {
	return malloc(size);
}
