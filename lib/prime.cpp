#include <assert.h>
#include <vector>
#include <algorithm>

static std::vector<unsigned long long> primes = { 2 };
static unsigned long long largest_known = 2;

int is_prime(unsigned long long n)
{
	dprintf("Is %llu prime? ", n);
	while(n > largest_known + 1) {
		if(((largest_known + 1) & 1) == 0) {
			largest_known++;
		} else {
			is_prime(largest_known + 1);
		}
	}
	if(largest_known > n) {
		if(std::binary_search(primes.begin(), primes.end(), n)) {
			dprintf("yes (cached)\n");
			return true;
		}
	}
	assert(largest_known < n);
	largest_known = n;
	for(auto& p : primes) {
		if(n % p == 0) {
			dprintf("no (%llu)\n", p);
			return false;
		}
	}
	primes.push_back(n);
	dprintf("yes\n");
	return true;
}
