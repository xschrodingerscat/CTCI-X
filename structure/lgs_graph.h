



#ifndef __LGS_GRAPH_H_INCLUDE__
#define __LGS_GRAPH_H_INCLUDE__

#include "lgs_list.h"

#define LGS_GRAPH_PRIM      
#define LGS_GRAPH_KRUSKAL_NO

// relationship list
typedef struct lgs_graph_rlist {
	void *vtx;
	lgs_list *adj;
} lgs_graph_rlist;


typedef struct lgs_graph {
	int vtx_cnt;
	int edg_cnt;

	int (*match) (void *key1, void *key2);
	void (*destroy) (void *data);

	lgs_list *adj_lists;
} lgs_graph;

#define lgs_graph_vtx_cnt(g) (g->vtx_cnt)
#define lgs_graph_edg_cnt(g) (g->edg_cnt)
#define lgs_graph_adj_lists(g) (g->adj_lists)


void lgs_graph_init(lgs_graph *g, 
		            int (*match) (void *key1, void *key2),
		            void (*destroy) (void *data));
void lgs_graph_destroy(lgs_graph *g);

bool lgs_graph_insert_vtx(lgs_graph *g, void *data);
bool lgs_graph_insert_edg(lgs_graph *g, void *data1, void *data2);

bool lgs_graph_remove_vtx(lgs_graph *g, void **data);
bool lgs_graph_remove_edg(lgs_graph *g, void *data1, void **data2);

bool lgs_graph_adj_list(lgs_graph *g, void *data, lgs_graph_rlist **r);
bool lgs_graph_is_adjaccent(lgs_graph *g, void *data1, void *data2);

typedef enum lgs_graph_color {
	LGS_GRAPH_WHITE,
	LGS_GRAPH_GRAY,
	LGS_GRAPH_BLACK
} lgs_graph_color;


#endif




