



#ifndef __LGS_STACK_H_INCLUDE__
#define __LGS_STACK_H_INCLUDE__

#include "lgs_list.h"

typedef struct lgs_stack {
	lgs_list *base;
} lgs_stack;


typedef void (*lgs_stack_free) (void *data);

lgs_stack *lgs_stack_create(lgs_stack_free xfree);
void lgs_stack_destroy(lgs_stack *s);

int lgs_stack_length(lgs_stack *s);
bool lgs_statc_empty(lgs_stack *s);

bool lgs_stack_push(lgs_stack *s, void *data);
void *lgs_stack_pop(lgs_stack *s);

void *lgs_stack_peek(lgs_stack *s);

void lgs_stack_tranvers(lgs_stack *s, void (*visit) (void *obj, void *data));

#endif




