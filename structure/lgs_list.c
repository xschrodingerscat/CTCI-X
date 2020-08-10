


#include "../common/lgs_common.h"
#include "lgs_list.h"



lgs_list_node *
lgs_list_node_new(void *data)
{
	lgs_list_node *node = NULL;

	node = lgs_malloc(sizeof(lgs_list_node));
	node->data = data;

	return node;
}

lgs_list *
lgs_list_create(lgs_list_node_free xfree)
{
	lgs_list *l = NULL;

	l = lgs_malloc(sizeof(lgs_list));

	l->head.next = NULL;
	l->head.data = NULL;

	l->length = 0;
	l->xfree = xfree;

	return l;
}

void lgs_list_destroy(lgs_list *l) {

	lgs_list_node *node = NULL, *h = &(l->head);
	while (!lgs_list_empty(l)) {
		node = h->next;
		lgs_assert(node != NULL);
		h->next = node->next;

		if (l->xfree)
			l->xfree(node->data);
		lgs_free(node);
		l->length --;
	}

	lgs_free(l);
	l = NULL;
}

inline bool 
lgs_list_empty(lgs_list *l)
{
	return l->length == 0;
}

inline int 
lgs_list_length(lgs_list *l)
{
	return l->length;
}

bool
lgs_list_insert(lgs_list *l, int i, void *data)
{
	lgs_list_node *node = NULL, *p = NULL, *h = &(l->head);
	int k = 0;

	if (l == NULL || i < 0 || i > l->length)
		return false;

	for (p = h, k = 0; p != NULL && k < i; p = p->next, k ++);

	node = lgs_list_node_new(data);

	node->next = p->next;
	p->next = node;
	l->length ++;

	return true;
}

bool 
lgs_list_insert_head(lgs_list *l, void *data)
{
	return lgs_list_insert(l, 0, data);
}

bool 
lgs_list_insert_tail(lgs_list *l, void *data)
{
	return lgs_list_insert(l, l->length, data);
}

void *
lgs_list_remove(lgs_list *l, void *data, lgs_list_node_cmp cmp)
{
	lgs_list_node *node = NULL, *prev = NULL, *h = &(l->head);

	if (cmp == NULL || l == NULL || l->length == 0)
		return NULL;

	// found node with data and cmp does't equal to null
	prev = h;
	lgs_list_for_each(l, node) {
		if (cmp(node->data, data) == 0)
			break;
		prev = node;
	}

	// not found the node with data
	if (node == NULL)
		return NULL;

	prev->next = node->next;
	data = node->data;
	lgs_free(node);
	l->length --;

	return data;
}

void *
lgs_list_remove_ith(lgs_list *l, int i) 
{
	lgs_list_node *node = NULL, *prev = NULL, *h = &(l->head);
	void *data = NULL;
	int k = 0;

	if (l == NULL || l->length == 0 || i < 0 || i > l->length)
		return NULL;

	prev = h;
	lgs_list_for_each(l, node) {
		if (k == i)
			break;
		k ++;
		prev = node;
	}

	prev->next = node->next;
	data =  node->data;
	lgs_free(node);
	l->length --;

	return data;
}

void * 
lgs_list_remove_head(lgs_list *l)
{
	return lgs_list_remove_ith(l, 0);
}

void * 
lgs_list_remove_tail(lgs_list *l)
{
	return lgs_list_remove_ith(l, l->length - 1);
}

void *
lgs_list_ith(lgs_list *l, int i)
{
	lgs_list_node *node = NULL;
	int k = 0;

	if (l == NULL || i < 0 || i > l->length)
		return NULL;

	for (node = l->head.next, k = 0; node && k < i; node = node -> next, k ++);

	return node->data;
}

void *
lgs_list_head(lgs_list *l)
{
	return lgs_list_ith(l, 0);
}

void *
lgs_list_tail(lgs_list *l)
{
	return lgs_list_ith(l, l->length);
}

int 
lgs_list_find(lgs_list *l, void *data, lgs_list_node_cmp cmp)
{
	lgs_list_node *node = NULL;
	int i = 0;

	if (cmp == NULL)
		return LGS_ERROR;

	lgs_list_for_each(l, node) {
		if (cmp(data, node->data) == 0)	
			break;
		i ++;
	}

	if (node == NULL)
		return  LGS_ERROR;

	return i;
}

void 
lgs_list_tranverse(lgs_list *l, void (*visit)(void *obj, void *data))
{
	lgs_list_node *node = NULL;

	lgs_list_for_each(l, node) {
		if (visit) {
			visit(NULL, node->data);
		}
	}
}


