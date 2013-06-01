#include "../lib/args.cpp"
#include "../lib/prime.cpp"

int solve(ull_t n)
{
	ull_t t = 3;
	while(primes.size() < n) {
		is_prime(t++);
	}
	printf("%lluth prime: %llu\n", n, largest_known);
	check_result(n == 6, largest_known == 13);
	return 0;
}
