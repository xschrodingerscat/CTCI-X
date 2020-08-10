




#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "lgs_graph.h"


#define TEST_GRAPH_DATA(data)  (*(int *)data)


void
test_graph_free(void *data)
{
	lgs_free(data);
}

int 
test_graph_match(void *data1, void *data2)
{
	int val1 = TEST_GRAPH_DATA(data1);
	int val2 = TEST_GRAPH_DATA(data2);

	if (val1 > val2)
		return 1;
	else if (val1 == val2)
		return 0;

	return -1;
}

void 
TestGraphCase(CuTest *tc) 
{
	lgs_graph g;

	lgs_graph_init(&g, test_graph_match, test_graph_free);
	lgs_graph_destroy(&g);
}

CuSuite *CuGraphSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestGraphCase);

	return suite;
}




