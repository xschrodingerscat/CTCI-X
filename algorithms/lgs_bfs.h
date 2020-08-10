



#ifndef __LGS_BFS_H_INCLUDE__
#define __LGS_BFS_H_INCLUDE__

#include "../common/lgs_common.h"
#include "../structure/lgs_list.h"
#include "../structure/lgs_graph.h"


typedef struct lgs_bfs_vertext {

	void *data;
	lgs_graph_color color;
	int hops;

}lgs_bfs_vtx;

bool lgs_graph_bfs(lgs_graph *g, lgs_bfs_vtx *start, lgs_list *hops);

#endif





