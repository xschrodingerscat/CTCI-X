




#ifndef __LGS_STRING_BUILDER_H_INCLUDE__
#define __LGS_STRING_BUILDER_H_INCLUDE__

#include "lgs_vector.h"

typedef struct lgs_string_builder {
	lgs_vector *v;
	char *base;
	int size;
} lgs_string_builder;

lgs_string_builder *lgs_string_builder_create();
void lgs_string_builder_destroy(lgs_string_builder *b);


bool lgs_string_builder_append(lgs_string_builder *b, char *str);
char *lgs_string_builder_to_str(lgs_string_builder *b);

#endif
