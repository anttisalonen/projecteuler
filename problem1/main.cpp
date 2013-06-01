#include <stdio.h>
#include <stdlib.h>

#include "../lib/args.cpp"

int solve(ull_t n)
{
	int sum = 0;
	for(int i = 0; i < n; i++) {
		if(i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	check_result(n == 10, sum == 23);
	return 0;
}

