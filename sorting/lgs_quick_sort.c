

#include "lgs_common.h"
#include "lgs_quick_sort.h"


void exchange(void *e1, void *e2, int offset);
int check_params(void *base, int size, int offset, lgs_qs_cmp compare);
int preproc(void *base, int offset, int l, int r, lgs_qs_cmp compare);
void quick_sort(void *base, int offset, int l, int r, lgs_qs_cmp compare);

int
lgs_quick_sort(void *base, int size, int offset, lgs_qs_cmp compare)
{
	if (check_params(base, size, offset, compare) != LGS_OK) 
		return LGS_ERROR;

	quick_sort(base, offset, 0, size - 1, compare);

	return LGS_OK;
}

int 
check_params(void *base, int size, int offset, lgs_qs_cmp compare)
{
	if (base == NULL || compare == NULL || size <= 0 
		|| offset <= 0 || offset > size) 
	{
		assert(base != NULL);
		assert(compare != NULL);
		assert(size > 0);
		assert(offset > 0);
		assert(offset <= size);
		return LGS_ERROR;
	}

	return LGS_OK;
}

void 
exchange(void *e1, void *e2, int offset)
{
	int8_t *t = (int8_t *) lgs_malloc(offset);

	lgs_copy(t, e1, offset);
	lgs_copy(e1, e2, offset);
	lgs_copy(e2, t, offset);

	lgs_free(t);
}

int 
preproc(void *base, int offset, int l, int r, lgs_qs_cmp compare)
{
	int i = 0, j = 0;
	int8_t *elem = NULL;
	int8_t *node = NULL, *a = NULL, *b = NULL;

	elem = (int8_t *)base;	

	i = l - 1;
	node = elem + r * offset;

	for (j = l; j < r; ++ j) {
		b = elem + j * offset;

		if (compare(b, node) <= 0) {
			i = i + 1;
			a = elem + i * offset;
			exchange(a, b, offset);
		}
	}

	a = elem + (i + 1) * offset;
	exchange(node, a, offset);
	return i + 1;
}

void 
quick_sort(void *base, int offset, int l, int r, lgs_qs_cmp compare)
{
	int m = 0;

	if (l < r) {
		m = preproc(base, offset, l, r, compare);
		quick_sort(base, offset, l, m - 1, compare);
		quick_sort(base, offset, m + 1, r, compare);
	}
}




