#include "munit/munit.h"
#include "dotproduct.h"

const int overflow_vector_a[] = { INT_MAX, 2, 3 };
const int vector_a[] = { 1, 2, 3 };
const int vector_b[] = { 4, 5, 6 };

MunitResult test_null_vector()
{
	int VECTOR_A_SIZE = sizeof(vector_a) / sizeof(*vector_a);
	int dot_product_result = dot_product(NULL, vector_b, VECTOR_A_SIZE);

	munit_assert_int(dot_product_result, ==, -2);

	return MUNIT_OK;
}

MunitResult test_overflow_integer()
{
	int VECTOR_A_SIZE = sizeof(overflow_vector_a) / sizeof(*overflow_vector_a);
	int dot_product_result = dot_product(overflow_vector_a, vector_b, VECTOR_A_SIZE);

	munit_assert_int(dot_product_result, ==, -1);

	return MUNIT_OK;
}

MunitResult test_correct_result()
{
	int VECTOR_A_SIZE = sizeof(vector_a) / sizeof(*vector_a);
	int dot_product_result = dot_product(vector_a, vector_b, VECTOR_A_SIZE);

	munit_assert_int(dot_product_result, ==, 32);

	return MUNIT_OK;
}

MunitTest tests[] = {
		{
				"/null-vector", /* name */
				test_null_vector, /* test */
				NULL, /* setup */
				NULL, /* tear_down */
				MUNIT_TEST_OPTION_NONE, /* options */
				NULL /* parameters */
		},
		{
				"/overflow-sum", /* name */
				test_overflow_integer, /* test */
				NULL, /* setup */
				NULL, /* tear_down */
				MUNIT_TEST_OPTION_NONE, /* options */
				NULL /* parameters */
		},
		{
				"/correct-dot-product", /* name */
				test_correct_result, /* test */
				NULL, /* setup */
				NULL, /* tear_down */
				MUNIT_TEST_OPTION_NONE, /* options */
				NULL /* parameters */
		},
		/* Mark the end of the array with an entry where the test
		 * function is NULL */
		{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
		"/dot-product", /* name */
		tests, /* tests */
		NULL, /* suites */
		1, /* iterations */
		MUNIT_SUITE_OPTION_NONE /* options */
};

int run_dotproduct_tests(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return munit_suite_main(&suite, NULL, argc, argv);
}