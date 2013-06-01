#include <math.h>
#include <string>

#include "../lib/args.cpp"

bool is_palindrome(const std::string& s)
{
	size_t l = s.length();
	for(size_t i = 0; i < l / 2; i++) {
		if(s[i] != s[l - i - 1])
			return false;
	}
	return true;
}

bool is_palindrome(ull_t l)
{
	std::string s = std::to_string(l);
	return is_palindrome(s);
}

int solve(ull_t n)
{
	ull_t found = 0;
	ull_t t = pow(10, n) - 1;
	for(ull_t f1 = t; f1 > 0; f1--) {
		for(ull_t f2 = f1; f2 > 0; f2--) {
			ull_t v = f1 * f2;
			if(is_palindrome(v)) {
				if(v > found) {
					found = v;
				}
				break;
			}
		}
	}
	printf("Palindrome: %llu\n", found);
	check_result(n == 2, found = 9009);
	return 0;
}
