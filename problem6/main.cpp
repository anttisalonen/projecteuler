#include <math.h>
#include <string>

#include "../lib/args.cpp"

int solve(ull_t n)
{
	ull_t sum = 0;
	for(ull_t i = 0; i <= n; i++) {
		sum += i * i;
	}
	ull_t sum_square = 0;
	for(ull_t i = 0; i <= n; i++) {
		sum_square += i;
	}
	sum_square = sum_square * sum_square;
	printf("Sum of the squares: %llu\n", sum);
	printf("Square of the sum: %llu\n", sum_square);
	printf("Difference: %llu\n", sum_square - sum);
	check_result(n == 10, sum == 385 && sum_square == 3025);
	return 0;
}
