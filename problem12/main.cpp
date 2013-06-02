#include <math.h>
#include "../lib/args.cpp"

ull_t num_divisors(ull_t num)
{
	if(num == 1)
		return 1;

	dprintf("Factors for %llu: ", num);

	ull_t divs = 2;
	for(ull_t i = 2; i < sqrt(num); i++) {
		if(num % i == 0) {
			dprintf("%llu ", i);
			divs += 2;
		}
	}
	dprintf("\n");
	return divs;
}
 
int solve(ull_t n)
{
	ull_t triangle_num = 1;
	ull_t next_num = 2;
	while(1) {
		triangle_num += next_num;
		next_num++;
		ull_t divs = num_divisors(triangle_num);
		dprintf("\t%llu has %llu divisors.\n", triangle_num, divs);
		if(divs >= n) {
			break;
		}
	}
	printf("%llu is the first triangle number with %llu divisors.\n",
			triangle_num, n);
	check_result(n == 5, triangle_num == 28);
	return 0;
}

