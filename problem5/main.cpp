#include <math.h>
#include <string>

#include "../lib/args.cpp"

int solve(ull_t n)
{
	ull_t res = n + 1;
	while(1) {
		bool found = true;
		for(ull_t j = 2; j <= n; j++) {
			if(res % j != 0) {
				found = false;
				break;
			}
		}
		if(found) {
			break;
		} else {
			res++;
		}
	}
	printf("Evenly divisible: %llu\n", res);
	check_result(n == 10, res == 2520);
	return 0;
}
