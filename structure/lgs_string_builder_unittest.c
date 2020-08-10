



#include "../common/lgs_common.h"
#include "../cutest/lgs_cutest.h"

#include "lgs_string_builder.h"

void 
TestStringBuilderCase(CuTest *tc)
{
	char *sentances[] = {
		"Hello",
		" ",
		"World",
		"!",
		" ",
		"My",
		" ",
		"name",
		" ",
		"is",
		" ",
		"Shawn",
		"."
	};
	int i = 0;
	char *string = NULL, *data = NULL;
	int size = 0;
	int p = 0;


	lgs_string_builder *builder = lgs_string_builder_create();

	for (i = 0; i < LGS_ARRAY_SIZE(sentances); ++ i) {
		lgs_string_builder_append(builder, sentances[i]);
	}

	string = lgs_string_builder_to_str(builder);

	for (i = 0; i < LGS_ARRAY_SIZE(sentances); ++ i) {
		size += strlen(sentances[i]);
	}

	size += 1;
	data = (char *) lgs_malloc(size);
	

	for (i = 0; i < LGS_ARRAY_SIZE(sentances); ++ i) {
		lgs_copy(data + p, sentances[i], lgs_strlen(sentances[i]));
		p += lgs_strlen(sentances[i]);
	}
	data[size - 1] = '\0';

	CuAssertTrue(tc, lgs_strcmp(data, string) == 0);

	lgs_string_builder_destroy(builder);
	lgs_free(data);
	data = NULL;
	builder = NULL;

}

CuSuite *CuStringBuilderSuite() 
{
	CuSuite *suite = CuSuiteNew();

	printf("---- String Builder Suite.\n");
	SUITE_ADD_TEST(suite, TestStringBuilderCase);

	return suite;
}





