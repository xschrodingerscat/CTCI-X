



#ifndef __LGS_LIST_H_INCLUDE__
#define __LGS_LIST_H_INCLUDE__

/*
 * list node
 * private
 */
typedef struct lgs_list_node {
	void *data;
	struct lgs_list_node *next;
} lgs_list_node;

lgs_list_node *lgs_list_node_new(void *data);


/*
 * list
 * public interface
 */

typedef int (*lgs_list_node_cmp)(void *node1, void *node2);
typedef void (*lgs_list_node_free)(void *data);

typedef struct lgs_list {
	lgs_list_node head;
	int length;
	lgs_list_node_free xfree;
} lgs_list;


#define lgs_list_for_each(l, node) \
	for (node = l->head.next; node != NULL; node = node->next)

#define lgs_list_data(n)         (n->data)

lgs_list *lgs_list_create(lgs_list_node_free xfree);
void lgs_list_destroy(lgs_list *l);

bool lgs_list_empty(lgs_list *l);
int lgs_list_length(lgs_list *l);

bool lgs_list_insert(lgs_list *l, int i, void *data);
bool lgs_list_insert_head(lgs_list *l, void *data);
bool lgs_list_insert_tail(lgs_list *l, void *data);

void *lgs_list_remove(lgs_list *l, void *data, lgs_list_node_cmp cmp);
void *lgs_list_remove_ith(lgs_list *l, int i);
void *lgs_list_remove_head(lgs_list *l);
void *lgs_list_remove_tail(lgs_list *l);

void *lgs_list_ith(lgs_list *l, int i);
void *lgs_list_head(lgs_list *l);
void *lgs_list_tail(lgs_list *l);


int lgs_list_find(lgs_list *l, void *data, lgs_list_node_cmp cmp);

void lgs_list_tranverse(lgs_list *l, void (*visit)(void *obj, void *data));

#endif




