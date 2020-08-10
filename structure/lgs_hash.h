



#ifndef __LGS_HASH_MAP_H_INCLUDE__
#define __LGS_HASH_MAP_H_INCLUDE__


#include "../common/lgs_common.h"
#include "lgs_vector.h"

typedef int (*lgs_hash_value) (void *data);
typedef void (*lgs_hash_free) (void *data);
typedef int (*lgs_hash_cmp) (void *e1, void *e2);

typedef struct lgs_hash {
	int flag;
	union {
		lgs_vector **v;
		int *a;
	} base;
	int length;
	int size;
	lgs_hash_value key_value;
	lgs_hash_free xfree;
} lgs_hash;


lgs_hash* lgs_hash_create(int flag, int size, 
		lgs_hash_value key_value, lgs_hash_free xfree);
void lgs_hash_destroy(lgs_hash *h);

bool lgs_hash_insert(lgs_hash *h, void *data);
void *lgs_hash_remove(lgs_hash *h, void *data, lgs_hash_cmp cmp);

int lgs_hash_length(lgs_hash *h);



#endif
