


#include "../common/lgs_common.h"
#include "lgs_hash.h"


lgs_hash* 
lgs_hash_create(int flag, int size, lgs_hash_value key_value, lgs_hash_free xfree)
{
	lgs_hash *h = NULL;
	int i = 0;

	if (flag != 0 && flag != 1)
		return NULL;

	if (size < 0 || key_value == NULL || xfree == NULL)
		return NULL;

	h = lgs_malloc(sizeof(lgs_hash));
	h->flag = flag;

	h->size = size;
	h->length = 0;
	h->key_value = key_value;
	h->xfree= xfree;

	if (h->flag == 0) {
		h->base.v = lgs_malloc(sizeof(lgs_vector *) * h->size);
		for (i = 0; i < h->size; ++ i) {
			h->base.v[i] = lgs_vector_create(xfree);
		}
	}
	else if (h->flag == 1) {
		h->base.a = lgs_malloc(sizeof(int) * h->size);
		for (i = 0; i < h->size; ++ i) {
			h->base.a[i] = 0;
		}
	}
	
	return h;
}

void 
lgs_hash_destroy(lgs_hash *h)
{
	int i = 0;

	if (h->flag == 0) {
		for (i = 0; i < h->size; ++ i) {
			lgs_vector_destroy(h->base.v[i]);
			h->base.v[i] = NULL;
		}
		lgs_free(h->base.v);
	} else if (h->flag == 1) {
		lgs_free(h->base.a);
	}

	lgs_free(h);
	h = NULL;
}

bool 
lgs_hash_insert(lgs_hash *h, void *data)
{
	int i = 0;

	i = h->key_value(data) % h->size;

	if (h->flag == 0) {
		if (!lgs_vector_insert(h->base.v[i], 0, data)) 
			return false;
		h->length ++;
		return true;
	} 
	
	h->base.a[i] ++ ;
	h->length ++;

	return true;
}

void *
lgs_hash_remove(lgs_hash *h, void *data, lgs_hash_cmp cmp)
{
	int i = 0;
	void *elem = NULL;

	i = h->key_value(data) % h->size;

	if (h->flag == 0) {
		elem = lgs_vector_remove(h->base.v[i], data, cmp);
		h->length --;
		return elem;
	} else {
		h->base.a[i] -- ;
		h->length --;
		return NULL;
	}
}

int 
lgs_hash_length(lgs_hash *h)
{
	if (h == NULL)
		return LGS_ERROR;

	return h == NULL ? LGS_ERROR : h->length;
}




