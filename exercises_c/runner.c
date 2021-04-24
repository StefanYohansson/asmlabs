#include "munit/munit.h"

int run_dotproduct_tests(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]);

int main (int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
	return run_dotproduct_tests(argc, argv);
}