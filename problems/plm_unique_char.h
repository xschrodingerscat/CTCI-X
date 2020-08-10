

#ifndef __PLM_UNIQUE_CHAR_H_INCLUDE__
#define __PLM_UNIQUE_CHAR_H_INCLUDE__

#include "../common/lgs_common.h"

typedef struct plm_hash_map  {
	uint64_t *base;
	int bits;
} plm_hash_map;


plm_hash_map *plm_hs_create(int bits);
void plm_hs_init(plm_hash_map *h);
void plm_hs_destory(plm_hash_map *h);

void plm_hs_set(plm_hash_map *h, unsigned int p);
bool plm_hs_test(plm_hash_map *h, unsigned int p);
void plm_hs_reset(plm_hash_map *h, unsigned int p);
void plm_hs_clean(plm_hash_map *h);

bool plm_is_unique_char(plm_hash_map *h, char *str);

#endif




