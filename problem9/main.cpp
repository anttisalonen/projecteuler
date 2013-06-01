#include <string.h>

#include "../lib/args.cpp"

static bool is_pythagorean(ull_t a, ull_t b, ull_t c)
{
	if(a < b && b < c)
		return a * a + b * b == c * c;
	return false;
}

int solve(ull_t n)
{
	for(ull_t k = 999; k > 2; k--) {
		for(ull_t j = k - 1; j > 1; j--) {
			for(ull_t i = j - 1; i >= 1; i--) {
				if(i + j + k == 1000) {
					if(is_pythagorean(i, j, k)) {
						printf("%llu + %llu + %llu = 1000\n",
								i, j, k);
						printf("Product = %llu\n", i * j * k);
						return 0;
					}
				}
			}
		}
	}
	return 0;
}


