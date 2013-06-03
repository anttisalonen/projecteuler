#include <math.h>
#include "../lib/args.cpp"

#if 0
int solve(ull_t n)
{
	ull_t i = 2;
	ull_t terms = 2;
	while(1) {
		if(i != 4 && ((i - 1) % 3) == 0) {
			i = (i - 1) / 3;
		} else {
			i = i * 2;
		}
		printf("%llu ", i);
		terms++;
		if(i <= 1)
			break;
		if(i > n * 4)
			break;
	}
	printf("Longest Collatz starting from %llu.\n", i);
	printf("Number of terms: %llu.\n", terms);

	return 0;
}
#endif

ull_t collatz_terms(ull_t i)
{
	ull_t terms = 1;
	while(i != 1) {
		if((i & 1) == 0)
			i /= 2;
		else
			i = 3 * i + 1;
		terms++;
	}
	return terms;
}

int solve(ull_t n)
{
	ull_t highest = 1;
	ull_t highest_terms = 1;

	for(ull_t i = 2; i <= n; i++) {
		ull_t num = collatz_terms(i);
		if(num > highest_terms) {
			highest_terms = num;
			highest = i;
		}
	}
	printf("Longest Collatz starting from %llu with %llu terms.\n",
			highest, highest_terms);

	return 0;
}

