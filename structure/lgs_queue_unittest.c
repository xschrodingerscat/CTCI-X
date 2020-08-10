

#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "lgs_queue.h"


void 
test_free_data(void *data)
{
	data = NULL;
}

#define TEST_QUEUE_TO_DATA(x)               (*(int *)x)

void 
test_visit_data(void *obj, void *data)
{
	int value = TEST_QUEUE_TO_DATA(data);

	obj = NULL;
	lgs_log("%d\n", value);

}

void 
TestQueueCase(CuTest *tc)
{
	int a[] =  {0, 2, 4, 3, 10, 9, 6, 34};
	int i = 0;
	void *data = NULL;
	int value = 0;

	lgs_queue *q = NULL;

	q = lgs_queue_create(test_free_data);

	for (i = 0; i < LGS_ARRAY_SIZE(a); ++ i) {
		lgs_queue_enque(q, &a[i]);
	}

	//lgs_queue_tranverse(q, test_visit_data);

	for (i = 0; i < LGS_ARRAY_SIZE(a); ++ i) {
		data = lgs_queue_peek(q);
		value = TEST_QUEUE_TO_DATA(data);
		CuAssertIntEquals(tc, value, a[i]);
		data = lgs_queue_deque(q);
		value = TEST_QUEUE_TO_DATA(data);
		CuAssertIntEquals(tc, value, a[i]);
	}

	lgs_queue_destroy(q);
}

CuSuite *CuQueueSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQueueCase);

	return suite;
}




