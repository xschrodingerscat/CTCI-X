

#include "../cutest/lgs_cutest.h"
#include "lgs_common.h"


void 
TestCommonCase(CuTest *tc)
{

}

CuSuite *
CuClockSuite()
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestCommonCase);

	return suite;
}
