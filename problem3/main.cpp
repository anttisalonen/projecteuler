#include <assert.h>
#include <vector>
#include <set>

#include "../lib/args.cpp"
#include "../lib/prime.cpp"

int solve(unsigned long long n)
{
	unsigned long long fac = 2;
	if(fac % 2 == 0)
		fac++;
	while(fac < n) {
		if (n % fac == 0) {
#if 0
			if(is_prime(fac)) {
				printf("Factor: %llu\n", fac);
				return 0;
			}
#else
			printf("%llu * %llu = %llu\n", fac, n / fac, n);
			if(solve(n / fac)) {
				printf("Factor: %llu\n", n / fac);
				check_result(n == 13195, n / fac == 29);
			}
			return 0;
#endif
		}
		fac++;
	}
	printf("prime\n");
	return 1;
}
