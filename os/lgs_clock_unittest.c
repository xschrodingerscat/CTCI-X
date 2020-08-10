


#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "../os/lgs_clock.h"

void 
TestClockCase(CuTest *tc)
{
	lgs_clock clk;

	lgs_clock_start(&clk);
	lgs_clock_stop(&clk);

	double delta = lgs_clock_duration(&clk);

	CuAssertDblEquals(tc, delta, 0, 0.001);
}

CuSuite *
CuClockSuite()
{
	CuSuite *suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestClockCase);

	return suite;
}
