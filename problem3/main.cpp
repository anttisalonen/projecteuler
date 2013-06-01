#include <assert.h>
#include <vector>
#include <set>

#include "../lib/args.cpp"

int is_prime(unsigned long long n)
{
	static std::set<unsigned long long> primes = { 2 };
	static unsigned long long largest_known = 2;
	dprintf("Is %llu prime? ", n);
	while(n > largest_known) {
		is_prime(largest_known++);
	}
	unsigned long long largest_known_prime = *primes.rbegin();
	if(largest_known_prime > n) {
		if(primes.find(n) != primes.end()) {
			dprintf("yes (cached)\n");
			return true;
		}
	}
	for(auto& p : primes) {
		if(n % p == 0) {
			dprintf("no (%llu)\n", p);
			return false;
		}
	}
	primes.insert(n);
	dprintf("yes\n");
	return true;
}

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
			}
			return 0;
#endif
		}
		fac++;
	}
	printf("prime\n");
	return 1;
}
