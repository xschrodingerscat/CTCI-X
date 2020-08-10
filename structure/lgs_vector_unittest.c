



#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"

#include "lgs_vector.h"

void 
vect_data_free(void *data) {
	data = NULL;
}

#define VECT_TO_DATA(x) *(int *)x

int 
vect_node_cmp(void *node1, void *node2)
{
	int a1 = VECT_TO_DATA(node1);
	int a2 = VECT_TO_DATA(node2);

	if (a1 == a2) 
		return 0;
	else if (a1 > a2)
		return 1;
	
	return -1;
}


void
TestVectorCase(CuTest *tc) {
	int data[] = { 2, 4, 6, 8, 0};
	void *elem = NULL;
	bool ret = false;
	lgs_vector *v = lgs_vector_create(vect_data_free);

	CuAssertTrue(tc, lgs_vector_empty(v));
	CuAssertTrue(tc, lgs_vector_length(v) == 0);

	ret = lgs_vector_insert(v, 0, &data[0]);
	CuAssertTrue(tc, ret);
	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 1);

	ret = lgs_vector_insert(v, 1, &data[1]);
	CuAssertTrue(tc, ret);
	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 2);

	ret = lgs_vector_insert(v, 2, &data[2]);
	CuAssertTrue(tc, ret);
	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 3);

	ret = lgs_vector_insert(v, 3, &data[3]);
	CuAssertTrue(tc, ret);
	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 4);

	ret = lgs_vector_insert(v, 3, &data[4]);
	CuAssertTrue(tc, ret);
	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 5);

	ret = lgs_vector_insert(v, 6, &data[4]);
	CuAssertTrue(tc, ret == false);
	ret = lgs_vector_insert(v, -1, &data[4]);
	CuAssertTrue(tc, ret == false);

	elem = lgs_vector_remove_ith(v, -1);
	CuAssertPtrEquals(tc, elem, NULL);
	elem = lgs_vector_remove_ith(v, 6);
	CuAssertPtrEquals(tc, elem, NULL);

	CuAssertTrue(tc, lgs_vector_empty(v) == false);
	CuAssertTrue(tc, lgs_vector_length(v) == 5);


	//  array = { 2, 4, 6, 0, 8}
	elem = lgs_vector_remove_ith(v, 0);
	CuAssertPtrNotNull(tc, elem);
	CuAssertIntEquals(tc, VECT_TO_DATA(elem), 2);

	elem = lgs_vector_remove_ith(v, 0);
	CuAssertPtrNotNull(tc, elem);
	CuAssertIntEquals(tc, VECT_TO_DATA(elem), 4);

	elem = lgs_vector_remove(v, &data[2], vect_node_cmp);
	CuAssertPtrNotNull(tc, elem);
	CuAssertIntEquals(tc, VECT_TO_DATA(elem), 6);

	elem = lgs_vector_remove(v, &data[4], vect_node_cmp);
	CuAssertPtrNotNull(tc, elem);
	CuAssertIntEquals(tc, VECT_TO_DATA(elem), 0);

	elem = lgs_vector_remove(v, &data[3], vect_node_cmp);
	CuAssertPtrNotNull(tc, elem);
	CuAssertIntEquals(tc, VECT_TO_DATA(elem), 8);

	CuAssertTrue(tc, lgs_vector_empty(v));
	CuAssertTrue(tc, lgs_vector_length(v) == 0);

	lgs_vector_destroy(v);
	v = NULL;
}


CuSuite *CuVectorSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestVectorCase);

	return suite;
}




