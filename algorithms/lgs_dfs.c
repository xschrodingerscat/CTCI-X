



#include "lgs_dfs.h"

bool 
graph_dfs(lgs_graph *g, lgs_graph_rlist *r, lgs_list *l)
{
	lgs_dfs_vtx *v = NULL, *adj_v = NULL;
	lgs_list_node *node = NULL;
	lgs_graph_rlist *clr_adjlist = NULL;


	v = r->vtx;
	v->color = LGS_GRAPH_GRAY;
	lgs_list_for_each(r->adj, node) {
		adj_v = lgs_list_data(node);

		if (!lgs_graph_adj_list(g, adj_v, &clr_adjlist))
			return false;

		v = clr_adjlist->vtx;

		if (v->color == LGS_GRAPH_WHITE)
			if (!graph_dfs(g, clr_adjlist, l))
				return false;
	}

	((lgs_dfs_vtx *)(r->vtx))->color = LGS_GRAPH_BLACK;

	lgs_list_insert_head(l, r->vtx);

	return true;
}

bool 
lgs_graph_dfs(lgs_graph *g, lgs_list *l)
{
	lgs_list_node *node = NULL;
	lgs_dfs_vtx *v = NULL;

	lgs_list_for_each(lgs_graph_adj_lists(g), node) {
		v = ((lgs_graph_rlist *)lgs_dfs_vtx_data(node))->vtx;
		v->color = LGS_GRAPH_WHITE;
	}


	lgs_list_for_each(lgs_graph_adj_lists(g), node) {
		v = ((lgs_graph_rlist *)lgs_dfs_vtx_data(node))->vtx;

		if (v->color == LGS_GRAPH_WHITE) {
			if (!graph_dfs(g, lgs_dfs_vtx_data(node), l))
				return false;
		}
	}

	return true;
}



