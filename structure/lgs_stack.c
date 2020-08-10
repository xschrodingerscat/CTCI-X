




#include "../common/lgs_common.h"
#include "lgs_stack.h"



lgs_stack *
lgs_stack_create(lgs_stack_free xfree)
{
	lgs_stack *s = NULL;

	s = lgs_malloc(sizeof(lgs_stack));
	s->base = lgs_list_create(xfree);

	return s;
}

void 
lgs_stack_destroy(lgs_stack *s)
{
	lgs_list_destroy(s->base);
	lgs_free(s);
}

int 
lgs_stack_length(lgs_stack *s)
{
	return lgs_list_length(s->base);
}

bool 
lgs_statc_empty(lgs_stack *s)
{
	return lgs_stack_length(s) == 0;
}

bool 
lgs_stack_push(lgs_stack *s, void *data)
{
	return lgs_list_insert_head(s->base, data);
}

void *
lgs_stack_pop(lgs_stack *s)
{
	return lgs_list_remove_head(s->base);
}

void *
lgs_stack_peek(lgs_stack *s)
{
	return lgs_list_head(s->base);
}


void 
lgs_stack_tranvers(lgs_stack *s, void (*visit) (void *obj, void *data))
{
	lgs_list_tranverse(s->base, visit);	
}




