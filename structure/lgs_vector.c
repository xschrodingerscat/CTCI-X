


#include "../common/lgs_common.h"
#include "lgs_vector.h"


lgs_vector *
lgs_vector_create(void (*xfree)(void *data))
{
	lgs_vector *v = NULL;

	v = lgs_malloc(sizeof(lgs_vector));
	v->xfree = xfree;

	lgs_vector_init(v);

	return v;
}

void 
lgs_vector_init(lgs_vector *v)
{
	v->size = 1;
	v->length = 0;
	v->base = lgs_malloc(sizeof(void *) * v->size);
}

void 
lgs_vector_destroy(lgs_vector *v)
{
	int i = 0;
	for (i = 0; i <v->length; ++ i) {
		if (v->xfree)
			v->xfree(v->base[i]);
	}
	lgs_free(v->base);
	lgs_free(v);
}

void 
lgs_vector_increase(lgs_vector *v) 
{
	void **base = NULL;
	int size = 0;

	size = v->size * LGS_VECTOR_INC_FACTOR;
	base = lgs_malloc(sizeof(void *) * size);
	lgs_copy(base, v->base, v->size * sizeof(void *));
	lgs_free(v->base);
	v->base = base;
	v->size = size;
}

bool 
lgs_vector_insert(lgs_vector *v, int i, void *data)
{
	int k = 0;

	if (v == NULL || i < 0 || i > v->length)
		return false;

	if (v->length == v->size) {
		lgs_vector_increase(v);
	}

	for (k = v->length; k > i; -- k)
		v->base[k] = v->base[k - 1];

	v->base[i] = data;
	v->length ++;

	return true;
}

bool 
lgs_vector_insert_tail(lgs_vector *v, void *data)
{
	return lgs_vector_insert(v, v->length, data);
}

void *
lgs_vector_remove_ith(lgs_vector *v, int i)
{
	void *elem = NULL;
	int k = 0;
	if (v == NULL || i < 0 || i > v->length - 1)
		return NULL;

	k = i;
	elem = v->base[k];
	while (k + 1 < v->length) {
		v->base[k] = v->base[k + 1];
		k ++;
	}
	v->length --;

	return elem;
}

void *
lgs_vector_remove(lgs_vector *v, void *data, lgs_vector_cmp cmp)
{
	int i;

	if (v == NULL || cmp == NULL)
		return NULL;

	i = lgs_vector_find(v, data, cmp);

	if (i == LGS_ERROR)
		return NULL;

	return lgs_vector_remove_ith(v, i);
}

void *
lgs_vector_ith(lgs_vector *v, int i)
{
	if (v == NULL || i < 0 || i > v->length - 1)
		return NULL;

	return v->base[i];
}

int 
lgs_vector_find(lgs_vector*v, void *data, lgs_vector_cmp cmp)
{
	int i = 0;

	if (v == NULL || cmp == NULL)
		return LGS_ERROR;

	for (i = 0; i <v->length; ++ i) {
		if (cmp(v->base[i], data) == 0)
			return i;
	}
	return LGS_ERROR;
}

int 
lgs_vector_length(lgs_vector *v)
{
	return v->length;
}

bool 
lgs_vector_empty(lgs_vector *v)
{
	return v->length == 0;
}

void 
lgs_vector_tranverse(lgs_vector *v, void (*visit)(void *data))
{
	int i = 0;
	for (i = 0; i < v->length; ++ i) {
		if (visit) 
			visit(v->base[i]);
	}
}




