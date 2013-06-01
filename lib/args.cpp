#include <stdio.h>
#include <stdlib.h>

int solve(unsigned long long n);

int main(int argc, char** argv)
{
	unsigned long long n = atoll(argv[1]);
	return solve(n);
}

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...)
#endif

