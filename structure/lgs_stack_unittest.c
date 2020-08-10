




#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "lgs_stack.h"



#define TEST_STACK_TO_DATA(x)   (*(int *)x)

void 
TestStackCase(CuTest *tc)
{
	int a[] =  {0, 2, 4, 3, 10, 9, 6, 34};
	int i = 0;
	void *data = NULL;
	int value = 0;


	lgs_stack *s = lgs_stack_create(NULL);


	for (i = 0; i < LGS_ARRAY_SIZE(a); ++ i) {
		lgs_stack_push(s, &a[i]);
	}

	for (i = 0; i < LGS_ARRAY_SIZE(a); ++ i) {
		data = lgs_stack_pop(s);
		value = TEST_STACK_TO_DATA(data);

		CuAssertIntEquals(tc, value, a[LGS_ARRAY_SIZE(a) - i - 1]);
	}

	lgs_stack_destroy(s);
}

CuSuite *CuStackSuite() 
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestStackCase);

	return suite;
}
