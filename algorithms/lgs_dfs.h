




#ifndef __LGS_DFS_H_INCLUDE__
#define __LGS_DFS_H_INCLUDE__

#include "../common/lgs_common.h"
#include "../structure/lgs_graph.h"
#include "../structure/lgs_list.h"


typedef struct lgs_dfs_vertex {
	void *data;
	lgs_graph_color color;
} lgs_dfs_vtx;


#define lgs_dfs_vtx_data(x)			((x)->data)


bool lgs_graph_dfs(lgs_graph *g, lgs_list *l);

#endif





