#ifndef __LGS_COMMON_H_INCLUDE__
#define __LGS_COMMON_H_INCLUDE__

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



#define LGS_OK               0
#define LGS_ERROR            (-1)

#define LGS_TRUE             1;
#define LGS_FALSE            0


#define LGS_ARRAY_SIZE(x)    (sizeof(x)/sizeof(x[0]))


void lgs_copy(void *dst, void *src, int size);
void lgs_free(void *p);
void *lgs_malloc(int size);



#endif
