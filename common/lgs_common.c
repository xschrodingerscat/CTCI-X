

#include "lgs_common.h"

int lgs_ref = 0;

void 
lgs_copy(void *dst, void *src, int size)
{
	memcpy(dst, src, size);
}

void
lgs_free(void *p)
{
	lgs_ref --;
	free(p);
}

void *
lgs_malloc(int size) 
{
	lgs_ref ++;
	return malloc(size);
}

void 
lgs_debug_start()
{
	lgs_ref = 0;
	printf("lgs mem debug start! ref = %d\n", lgs_ref);
}

void 
lgs_debug_stop()
{
	printf("lgs mem debug stop! ref = %d\n", lgs_ref);
	lgs_assert(lgs_ref == 0);
}
