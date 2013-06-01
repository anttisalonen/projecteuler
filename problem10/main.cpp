#include "../lib/args.cpp"

static std::vector<ull_t> sieve(ull_t n)
{
	std::vector<std::pair<ull_t, bool>> numbers;
	std::vector<ull_t> primes;

	for(ull_t i = 0; i <= n; i++) {
		numbers.push_back({i, false});
	}

	ull_t p = 2;
	while(p < n) {
		primes.push_back(p);
		ull_t multiplier = 1;
		while(p * multiplier <= n) {
			numbers[p * multiplier].second = true;
			multiplier++;
		}
		while(p < n) {
			p++;
			if(numbers[p].second == false) {
				break;
			}
		}
	}

	return primes;
}

int solve(ull_t n)
{
	auto primes = sieve(n);
	ull_t primes_sum = 0;
	for(auto& p : primes) {
		primes_sum += p;
	}
	printf("Sum of primes up to %llu = %llu\n", n, primes_sum);
	check_result(n == 10, primes_sum == 17);
	return 0;
}
