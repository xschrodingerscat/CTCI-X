



#ifndef __LGS_QUEUE_H_INCLUDE__
#define __LGS_QUEUE_H_INCLUDE__

#include "lgs_list.h"


typedef void (*lgs_queue_free) (void *data);

typedef struct lgs_queue {
	lgs_list *base;
}lgs_queue;


lgs_queue *lgs_queue_create(lgs_queue_free xfree);
void lgs_queue_destroy(lgs_queue *q);

int lgs_queue_length(lgs_queue *q);
bool lgs_queue_empty(lgs_queue *q);

bool lgs_queue_enque(lgs_queue *q, void *data);
void *lgs_queue_deque(lgs_queue *q);

void *lgs_queue_peek(lgs_queue *q);

void lgs_queue_tranverse(lgs_queue *q, void (*visit)(void *obj, void *data));

#endif




