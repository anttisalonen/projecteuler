static std::set<unsigned long long> primes = { 2 };
static unsigned long long largest_known = 2;

int is_prime(unsigned long long n)
{
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
