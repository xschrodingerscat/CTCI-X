

/* This is auto-generated code. Edit at your own peril. */
#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"

extern CuSuite *CuClockSuite();

void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();


	CuSuiteAddSuite(suite, CuClockSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void)
{
    RunAllTests();
}

/*
void TestCase(CuTest* tc) {
	CuFail(tc, "Error");
	CuAssertTrue(tc, 1 == 1);
	CuAssert(tc, "This is equaled!", 1==1);
	CuAssertIntEquals(tc, 1, 1);
	CuAssertDblEquals(tc, 1.0, 1.0, 0.001);
	CuAssertPtrEquals(tc, NULL, NULL);
	CuAssertPtrNotNull(tc, TestCase);
	CuAssertPtrNotNullMsg(tc, "TestCase", TestCase);
}
*/
