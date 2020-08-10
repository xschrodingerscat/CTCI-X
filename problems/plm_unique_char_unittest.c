

#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"
#include "plm_unique_char.h"
/*-------------------------------------------------------------------------*
 * Unique Char
 *-------------------------------------------------------------------------*/

void TestUniqueCharCase(CuTest* tc) 
{
/*
		"aaaaa"
		"abcdef",
		"helloword",
		"",
		"habedefgh",
		"ccdd",
		"-15a67*-+",
		"4&^a*"
*/
	plm_hash_map *h = plm_hs_create(256);
	CuAssertTrue(tc, plm_is_unique_char(h, "aaaaa"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "abcdef"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "helloword"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, ""));
	
	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "habedefgh"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "ccdd"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "-15a67*-+"));

	plm_hs_clean(h);
	CuAssertTrue(tc, plm_is_unique_char(h, "4&^a*"));

	plm_hs_destory(h);
}


/*-------------------------------------------------------------------------*
 * main
 *-------------------------------------------------------------------------*/


CuSuite *
CuUniqueCharSuite(void) {
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestUniqueCharCase);

	return suite;
}
