



#include "../common/lgs_common.h"
#include "lgs_queue.h"


lgs_queue *
lgs_queue_create(lgs_queue_free xfree)
{
	lgs_queue *q = NULL;

	q = lgs_malloc(sizeof(lgs_queue));
	q->base = lgs_list_create(xfree);

	return q;
}

void 
lgs_queue_destroy(lgs_queue *q)
{
	lgs_list_destroy(q->base);
	lgs_free(q);
}

inline int 
lgs_queue_length(lgs_queue *q)
{
	return lgs_list_length(q->base);
}

inline bool 
lgs_queue_empty(lgs_queue *q)
{
	return lgs_queue_length(q) == 0;
}

bool 
lgs_queue_enque(lgs_queue *q, void *data)
{
	return lgs_list_insert_tail(q->base, data);
}

void *
lgs_queue_deque(lgs_queue *q)
{
	return lgs_list_remove_head(q->base);
}

void *
lgs_queue_peek(lgs_queue *q)
{
	return lgs_list_head(q->base);
}


void 
lgs_queue_tranverse(lgs_queue *q, void (*visit)(void *obj, void *data))
{
	lgs_list_tranverse(q->base, visit);
}







