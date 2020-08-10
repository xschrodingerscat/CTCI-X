

#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "plm_unique_char.h"

plm_hash_map *
plm_hs_create(int bits)
{
	plm_hash_map *h = NULL; 

	if (bits <= 0)
		return NULL;

	h = lgs_malloc(sizeof(plm_hash_map));
	h->bits = (bits / 64) + ((bits % 64) != 0);

	h->base = lgs_malloc(h->bits * sizeof(uint64_t));
	plm_hs_init(h);

	return h;
}

void 
plm_hs_init(plm_hash_map *h) 
{
	int i = 0;
	int n = h->bits/sizeof(uint64_t);
	while (i < n)
		h->base[i++] = 0;
}

void 
plm_hs_destory(plm_hash_map *h) 
{
	lgs_free(h->base);
	h->base = NULL;

	lgs_free(h);
	h = NULL;
}

void 
plm_hs_set(plm_hash_map *h, unsigned int p)
{
	int n = p % sizeof(uint64_t);
	int i = p / sizeof(uint64_t);

	h->base[i] |= (uint64_t)1 << n;
	
}

bool 
plm_hs_test(plm_hash_map *h, unsigned int p)
{
	int n = p % sizeof(uint64_t);
	int i = p / sizeof(uint64_t);

	return h->base[i] & ((uint64_t)1 << n);
}

void 
plm_hs_reset(plm_hash_map *h, unsigned int p)
{
	int n = p % sizeof(uint64_t);
	int i = p / sizeof(uint64_t);

	h->base[i] &= ~((uint64_t)1 << n);
}

void 
plm_hs_clean(plm_hash_map *h)
{
	plm_hs_init(h);
}

bool 
plm_is_unique_char(plm_hash_map *h, char *str) 
{
	char *p = NULL;

	if (*str == 0)
		return true;

	for (p = str; *p != 0; p ++) {
		if (plm_hs_test(h, (uint8_t)*p))
			return true;
		else 
			plm_hs_set(h, (uint8_t)*p);
	} 

	return false;
}



