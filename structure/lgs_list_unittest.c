



#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "lgs_list.h"


void 
test_data_free(void *data) {
	data = NULL;
}

#define TEST_TO_DATA(x) *(int *)x

int 
test_node_cmp(void *node1, void *node2)
{
	int a1 = TEST_TO_DATA(node1);
	int a2 = TEST_TO_DATA(node2);

	if (a1 == a2) 
		return 0;
	else if (a1 > a2)
		return 1;
	
	return -1;
}

void 
TestListCase(CuTest *tc)
{

	lgs_list *l = lgs_list_create(NULL);
	int a[] = {1, 2, 3, 4, 5};

	CuAssertTrue(tc, lgs_list_empty(l));
	CuAssertTrue(tc, lgs_list_length(l) == 0);

	CuAssertPtrEquals(tc, l->head.next, NULL);

	// insert
	lgs_list_insert_head(l, &a[0]);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 1);

	lgs_list_insert_head(l, &a[1]);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 2);

	lgs_list_insert_head(l, &a[2]);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 3);

	lgs_list_insert_head(l, &a[3]);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 4);

	// delete
	lgs_list_remove_head(l);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 3);

	lgs_list_remove_head(l);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 2);

	lgs_list_remove_head(l);
	CuAssertTrue(tc, lgs_list_empty(l) == false);
	CuAssertTrue(tc, lgs_list_length(l) == 1);

	lgs_list_remove_head(l);
	CuAssertTrue(tc, lgs_list_empty(l) == true);
	CuAssertTrue(tc, lgs_list_length(l) == 0);

	CuAssertPtrEquals(tc, l->head.next, NULL);

	lgs_list_remove_head(l);
	CuAssertTrue(tc, lgs_list_empty(l) == true);
	CuAssertTrue(tc, lgs_list_length(l) == 0);

	CuAssertPtrEquals(tc, l->head.next, NULL);

	lgs_list_destroy(l);
}

CuSuite *CuListSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestListCase);

	return suite;
}
