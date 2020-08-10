

#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"

#include "lgs_dfs.h"

#define TEST_STR_SIZE         6

static void 
test_dfs_free(void *data)
{
	void *val = NULL;
	val = ((lgs_dfs_vtx *) data)->data;
	lgs_free(val);
	lgs_free(data);
}

static int 
test_dfs_match(void *key1, void *key2)
{
	return lgs_strcmp(((lgs_dfs_vtx *) key1)->data, ((lgs_dfs_vtx *) key2)->data);
}

static void 
test_dfs_tranverse(lgs_graph *g) 
{
	lgs_dfs_vtx *vtx;
	lgs_list_node *node, *elem;
	lgs_graph_rlist *r;
	int i = 0, j = 0;

	lgs_print(stdout, "Vertices=%d, edges=%d\n", 
			lgs_graph_vtx_cnt(g), 
			lgs_graph_edg_cnt(g));

	lgs_list_for_each(g->adj_lists, node) {
		r = lgs_list_data(node);
		vtx = r->vtx;
		lgs_print(stdout, "graph[%d]=%s: ", i ++, (char *)vtx->data);

		j = 0;
		lgs_list_for_each(r->adj, elem) {
			vtx = lgs_list_data(elem);
			if (j ++ > 0) 
				lgs_print(stdout, ", ");
			lgs_print(stdout, "%s", (char *)vtx->data);
		}

		lgs_print(stdout, "\n");
	}
}

void 
TestDfsCase(CuTest *tc) 
{
	char *netid_name[] = {
		"node1",
		"node2",
		"node3",
		"node4",
		"node5",
		"node6"
	};

	char *net_relations[][2] = {
		{"node1", "node2"},
		{"node2", "node1"},
		{"node1", "node3"},
		{"node3", "node1"},
		{"node2", "node3"},
		{"node3", "node2"},
		{"node2", "node4"},
		{"node4", "node2"},
		{"node3", "node5"},
		{"node5", "node3"},
		{"node4", "node5"},
		{"node5", "node4"},
		{"node5", "node6"},
		{"node6", "node5"}
	};

	lgs_graph g;
	lgs_dfs_vtx *netid, netid1, *netid2;
	lgs_list *list= NULL;
	lgs_list_node *node = NULL;

	int i = 0;
	char data1[TEST_STR_SIZE];

	lgs_graph_init(&g, test_dfs_match, test_dfs_free);

	// insert vertex
	for (i = 0; i < LGS_ARRAY_SIZE(netid_name); ++ i) {
		netid = lgs_malloc(sizeof(lgs_dfs_vtx));
		netid->data = lgs_malloc(sizeof(TEST_STR_SIZE));
		lgs_strcpy(netid->data, netid_name[i]);
		lgs_print(stdout, "Inserting vertex %s\n", (char *)netid->data);
		lgs_graph_insert_vtx(&g, netid);
	}

	// insert edges
	netid1.data = data1;
	for (i = 0; i < LGS_ARRAY_SIZE(net_relations); ++ i) {
		netid2 = lgs_malloc(sizeof(lgs_dfs_vtx));
		netid2->data = lgs_malloc(sizeof(TEST_STR_SIZE));
		lgs_strcpy(netid1.data, net_relations[i][0]);
		lgs_strcpy(netid2->data, net_relations[i][1]);
		lgs_print(stdout, "Inserting edge %s to %s\n", (char *)netid1.data, 
				(char *) netid2->data);
		lgs_graph_insert_edg(&g, &netid1, netid2);
	}
	
	test_dfs_tranverse(&g);

	lgs_print(stdout, "Generating the dfs-first search listing\n");
	list = lgs_list_create(NULL);
	lgs_strcpy(netid1.data, "node1");

	CuAssertTrue(tc, lgs_graph_dfs(&g, list));

	i = 0;
	lgs_list_for_each(list, node) {
		netid = lgs_list_data(node);
		lgs_print(stdout, "list[%d]=%s (color=%d)\n", 
				i ++, (char *)netid-> data, netid->color);
	}

	lgs_list_destroy(list);
	lgs_graph_destroy(&g);
}


CuSuite *CuDfsSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestDfsCase);

	return suite;
}

