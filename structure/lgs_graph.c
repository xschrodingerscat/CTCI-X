



#include "../common/lgs_common.h"
#include "lgs_graph.h"


void 
lgs_graph_init(lgs_graph *g, int (*match) (void *key1, void *key2),
		void (*destroy) (void *data))
{
	g->vtx_cnt = 0;
	g->edg_cnt = 0;
	g->match = match;
	g->destroy = destroy;

	g->adj_lists = lgs_list_create(NULL);
}

void 
lgs_graph_destroy(lgs_graph *g)
{
	lgs_list *adj = g->adj_lists;
	lgs_graph_rlist *r = NULL;

	/*lgs_list_node *node = NULL;*/
	/*lgs_list_for_each(adj, node) {*/
		/*r = lgs_list_data(node);*/

		/*lgs_log("debug : %p\n", r->adj);*/
	/*}*/

	while (lgs_list_length(adj) > 0) {
		r = lgs_list_remove_head(adj);
		lgs_assert(r != NULL);
		lgs_list_destroy(r->adj);
		if (g->destroy != NULL)
			g->destroy(r->vtx);
		lgs_free(r);
	}

	lgs_list_destroy(adj);
	lgs_memset(g, 0, sizeof(lgs_graph));
}


bool 
lgs_graph_insert_vtx(lgs_graph *g, void *data)
{
	lgs_list_node *n = NULL;
	lgs_graph_rlist *r = NULL;

	lgs_list_for_each(g->adj_lists, n) {
		if (g->match(data, n->data) == 0)
			return false;
	}

	r = lgs_malloc(sizeof(lgs_graph_rlist));
	r->vtx = data;
	r->adj = lgs_list_create(g->destroy);

	if (!lgs_list_insert_tail(g->adj_lists, r))
		goto failed;

	g->vtx_cnt ++;

	return true;

failed:
	lgs_list_destroy(r->adj);
	lgs_free(r);
	return false;
}

bool 
lgs_graph_insert_edg(lgs_graph *g, void *data1, void *data2)
{
	lgs_graph_rlist *r = NULL;
	lgs_list_node *node = NULL;
	lgs_list *adj = g->adj_lists;

	lgs_list_for_each(adj, node) {
		r = lgs_list_data(node);
		if (g->match(data2, r->vtx) == 0)
			break;
	}

	if (node == NULL)
		return false;

	lgs_list_for_each(adj, node) {
		r = lgs_list_data(node);
		if (g->match(data1, r->vtx) == 0)
			break;
	}

	if (node == NULL)
		return false;

	r = lgs_list_data(node);

	if (!lgs_list_insert_head(r->adj, (void *)data2))
		return false;

	g->edg_cnt ++;

	return true;
}

bool 
lgs_graph_remove_vtx(lgs_graph *g, void **data)
{
	lgs_list_node *node = NULL;
	lgs_graph_rlist *r = NULL, *t = NULL;

	bool found = false;
	lgs_graph_rlist *val = NULL;


	lgs_list_for_each(g->adj_lists, node) {
		r = lgs_list_data(node);
		if (LGS_ERROR != lgs_list_find(r->adj, *data, g->match))
			return false;

		if (g->match(*data, r->vtx) == 0) {
			t = r;
			found = true;
		}
	}

	if (!found || lgs_list_length(t->adj) > 0)
		return false;

	if ((val = lgs_list_remove(g->adj_lists, *data, g->match)) == NULL)
		return false;

	lgs_list_destroy(val->adj);
	*data = val;

	g->vtx_cnt --;

	return true;
}

bool 
lgs_graph_remove_edg(lgs_graph *g, void *data1, void **data2)
{
	lgs_graph_rlist *r = NULL;
	lgs_list_node *node = NULL;
	void *val = NULL;

	lgs_list_for_each(g->adj_lists, node) {
		r = lgs_list_data(node);
		if (g->match(data1, r->vtx) == 0) {
			break;
		}
	}

	if (node == NULL)
		return false;

	if ((val = lgs_list_remove(r->adj, *data2, g->match)) == NULL)
		return false;

	g->edg_cnt --;

	return true;
}

bool 
lgs_graph_adj_list(lgs_graph *g, void *data, lgs_graph_rlist **r)
{
	lgs_list_node *node = NULL;
	lgs_graph_rlist *l = NULL;

	lgs_list_for_each(g->adj_lists, node) {
		l = lgs_list_data(node);
		if (g->match(data, l->vtx) == 0) {
			break;
		}
	}

	if (node == NULL)
		return false;

	*r = l;

	return true;
}

bool 
lgs_graph_is_adjaccent(lgs_graph *g, void *data1, void *data2)
{
	lgs_list_node *node = NULL;
	lgs_graph_rlist * r = NULL;

	lgs_list_for_each(g->adj_lists, node) {
		r = lgs_list_data(node);
		if (g->match(data1, r->vtx) == 0)
			break;
	}

	if (node == NULL)
		return false;

	r = lgs_list_data(node);

	lgs_list_for_each(r->adj, node) {
		if (g->match(data2, lgs_list_data(node)))
			break;
	}
	
	if (node == NULL)
		return false;

	return true;
}




