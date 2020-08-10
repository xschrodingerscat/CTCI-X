



#include "lgs_bfs.h"
#include "../structure/lgs_queue.h"



bool 
lgs_graph_bfs(lgs_graph *g, lgs_bfs_vtx *start, lgs_list *hops)
{
	lgs_queue *q = NULL;
	lgs_list_node *node = NULL;
	lgs_bfs_vtx *clr_vtx = NULL, *adj_vtx = NULL;
	lgs_graph_rlist *clr_adjlist = NULL, *adj_list = NULL, *r = NULL;


	lgs_list_for_each(g->adj_lists, node) {
		r = lgs_list_data(node);
		clr_vtx = r->vtx;
		if (g->match(start, r->vtx) == 0) {
			clr_vtx->color = LGS_GRAPH_GRAY;
			clr_vtx->hops = 0;
		} else {
			clr_vtx->color = LGS_GRAPH_WHITE;
			clr_vtx->hops = -1;
		}
	}

	q = lgs_queue_create(NULL);

	if (!lgs_graph_adj_list(g, start, &clr_adjlist)) 
		goto failed;

	if (!lgs_queue_enque(q, clr_adjlist))
		goto failed;

	while (lgs_queue_length(q) > 0) {
		
		adj_list = lgs_queue_peek(q);

		lgs_list_for_each(adj_list->adj, node) {

			adj_vtx = lgs_list_data(node);

			if (!lgs_graph_adj_list(g, adj_vtx, &clr_adjlist))
				goto failed;

			clr_vtx = clr_adjlist->vtx;
			if (clr_vtx->color == LGS_GRAPH_WHITE) {
				clr_vtx->color = LGS_GRAPH_GRAY;
				clr_vtx->hops = ((lgs_bfs_vtx *)(adj_list->vtx))->hops + 1;

				if (!lgs_queue_enque(q, clr_adjlist))
					goto failed;
			}
		}

		if ((adj_list = lgs_queue_deque(q)) == NULL)
			goto failed;

		((lgs_bfs_vtx *) adj_list->vtx)->color = LGS_GRAPH_BLACK;
	}

	lgs_queue_destroy(q);

	lgs_list_for_each(g->adj_lists, node) {
		clr_vtx = ((lgs_graph_rlist *) lgs_list_data(node))->vtx;
		if (clr_vtx->hops != -1) {
			lgs_list_insert_tail(hops, clr_vtx);
		}
	}

	return true;

failed:
	lgs_queue_destroy(q);
	return false;

}




