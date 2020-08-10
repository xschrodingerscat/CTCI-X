



#include "../common/lgs_common.h"
#include "lgs_string_builder.h"

void 
lgs_string_builder_release(void *data)
{
	lgs_free(data);
}

lgs_string_builder *
lgs_string_builder_create()
{
	lgs_string_builder *b = NULL;

	b = lgs_malloc(sizeof(lgs_string_builder));
	b->size = 0;
	b->base = NULL;
	b->v = lgs_vector_create(lgs_string_builder_release);

	return b;
}

void 
lgs_string_builder_destroy(lgs_string_builder *b)
{
	if (b->base) {
		lgs_free(b->base);
		b->base = NULL;
	}
	lgs_vector_destroy(b->v);
	b->v = NULL;
	lgs_free(b);
	b = NULL;
}

bool 
lgs_string_builder_append(lgs_string_builder *b, char *str)
{
	int len = lgs_strlen(str);
	char *data = NULL;

	data = lgs_malloc(len + 1);
	lgs_copy(data, str, len + 1);
	b->size += len;

	return lgs_vector_insert_tail(b->v, data);
}

char *
lgs_string_builder_to_str(lgs_string_builder *b)
{
	char *str = NULL;
	int i = 0;
	int size = 0;

	if (b->base)
		lgs_free(b->base);

	b->base = lgs_malloc(b->size + 1);

	for (i = 0; i < lgs_vector_length(b->v); ++ i) {
		str = (char *) lgs_vector_ith(b->v, i);
		lgs_copy(b->base + size, str, lgs_strlen(str));
		size += lgs_strlen(str);
	}

	b->base[b->size] = '\0';
	return b->base;
}




