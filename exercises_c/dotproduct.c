#include "dotproduct.h"

int dot_product(const int *vector_a, const int *vector_b, int vector_size)
{
	if (vector_a == NULL || vector_b == NULL) {
		return -2;
	}

	int i, sum = 0;

	for (i = 0; i < vector_size; i++) {
		if (sum > (INT_MAX - (vector_a[i] * vector_b[i]))) {
			return -1;
		} else {
			sum += vector_a[i] * vector_b[i];
		}
	}

	return sum;
}