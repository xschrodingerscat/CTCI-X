


#ifndef __LGS_ARRAY_LIST_H_INCLUDE__
#define __LGS_ARRAY_LIST_H_INCLUDE__


#define LGS_VECTOR_INC_FACTOR			2


typedef void (*lgs_vector_free)(void *data);

/* array list */
typedef struct lgs_vector {
	void **base;
	int length;
	int size;
	lgs_vector_free xfree;
} lgs_vector;


typedef int (*lgs_vector_cmp)(void *e1, void *e2);

lgs_vector *lgs_vector_create(void (*xfree)(void *data));
void lgs_vector_init(lgs_vector *v);
void lgs_vector_destroy(lgs_vector *v);

bool lgs_vector_insert(lgs_vector *v, int i, void *data);
bool lgs_vector_insert_tail(lgs_vector *v, void *data);
void *lgs_vector_remove(lgs_vector *v, void *data, lgs_vector_cmp cmp);
void *lgs_vector_remove_ith(lgs_vector *v, int i);

void *lgs_vector_ith(lgs_vector *v, int i);
int lgs_vector_find(lgs_vector*v, void *data, lgs_vector_cmp cmp);

int lgs_vector_length(lgs_vector *v);
bool lgs_vector_empty(lgs_vector *v);

void lgs_vector_tranverse(lgs_vector *v, void (*visit)(void *data));

#endif



