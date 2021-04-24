#include "dotproduct.h"

const int vector_a[] = { 1, 2, 3 };
const int vector_b[] = { 4, 5, 6 };

int main()
{
	int VECTOR_A_SIZE = sizeof(vector_a) / sizeof(*vector_a);
	int VECTOR_B_SIZE = sizeof(vector_b) / sizeof(*vector_b);

	if (VECTOR_A_SIZE != VECTOR_B_SIZE) {
		printf("The two arrays should be the same size.\n");
	}
	int dot_product_result = dot_product(vector_a, vector_b, VECTOR_A_SIZE);

	printf("Dot product result is: %d\n", dot_product_result);
}