


#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"


#include "lgs_hash.h"


void 
hash_data_free(void *data) {
	data = NULL;
}

#define HASH_TO_DATA(x) (*(int *)x)

int 
hash_node_cmp(void *node1, void *node2)
{
	int a1 = HASH_TO_DATA(node1);
	int a2 = HASH_TO_DATA(node2);

	if (a1 == a2) 
		return 0;
	else if (a1 > a2)
		return 1;
	
	return -1;
}

int 
hash_key(void *data) 
{
	return HASH_TO_DATA(data);
}

void 
TestHashCase(CuTest *tc) 
{
	int data[] = { 0, 1, 2, 3, 4, 5, 254, 255, 256, 257};
	int size = 256;
	int flag = 0;
	int i = 0;
	bool ret = false;
	lgs_hash *h = NULL;
	void *elem = NULL;

	flag = 0;
	h = lgs_hash_create(flag, size, hash_key, hash_data_free);


	for (i = 0; i < LGS_ARRAY_SIZE(data); ++ i) {
		CuAssertTrue(tc, lgs_hash_length(h) == i);
		ret = lgs_hash_insert(h, &data[i]);
		CuAssertTrue(tc, ret);
	}

	CuAssertTrue(tc, lgs_hash_length(h) == i);

	CuAssertTrue(tc, lgs_vector_length(h->base.v[0]) == 2);
	CuAssertTrue(tc, lgs_vector_length(h->base.v[1]) == 2);

	CuAssertTrue(tc, lgs_vector_length(h->base.v[2]) == 1);
	CuAssertTrue(tc, lgs_vector_length(h->base.v[3]) == 1);
	CuAssertTrue(tc, lgs_vector_length(h->base.v[4]) == 1);
	CuAssertTrue(tc, lgs_vector_length(h->base.v[5]) == 1);

	CuAssertTrue(tc, lgs_vector_length(h->base.v[254]) == 1);
	CuAssertTrue(tc, lgs_vector_length(h->base.v[255]) == 1);

	for (i = 0; i < LGS_ARRAY_SIZE(data); ++ i) {
		elem = lgs_hash_remove(h, &data[i], hash_node_cmp);
		CuAssertPtrNotNull(tc, elem);
	}

	CuAssertTrue(tc, lgs_hash_length(h) == 0);

	lgs_hash_destroy(h);
	h = NULL;
	
	flag = 1;
	h = lgs_hash_create(flag, size, hash_key, hash_data_free);

	for (i = 0; i < LGS_ARRAY_SIZE(data); ++ i) {
		CuAssertTrue(tc, lgs_hash_length(h) == i);
		ret = lgs_hash_insert(h, &data[i]);
		CuAssertTrue(tc, ret);
	}

	CuAssertTrue(tc, h->base.a[0] == 2);
	CuAssertTrue(tc, h->base.a[1] == 2);

	CuAssertTrue(tc, h->base.a[2] == 1);
	CuAssertTrue(tc, h->base.a[3] == 1);
	CuAssertTrue(tc, h->base.a[4] == 1);
	CuAssertTrue(tc, h->base.a[5] == 1);

	CuAssertTrue(tc, h->base.a[254] == 1);
	CuAssertTrue(tc, h->base.a[255] == 1);

	for (i = 0; i < LGS_ARRAY_SIZE(data); ++ i) {
		elem = lgs_hash_remove(h, &data[i], hash_node_cmp);
		CuAssertPtrEquals(tc, elem, NULL);
	}

	CuAssertTrue(tc, lgs_hash_length(h) == 0);

	for (i = 0; i < size; ++ i) {
		CuAssertIntEquals(tc, h->base.a[i], 0);
	}

	lgs_hash_destroy(h);
	h = NULL;
}

CuSuite *CuHashSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestHashCase);

	return suite;
}





