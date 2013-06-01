#include <stdio.h>
#include <stdlib.h>

#include <assert.h>
#include <vector>
#include <set>

typedef unsigned long long ull_t;

int solve(ull_t n);

int main(int argc, char** argv)
{
	ull_t n = atoll(argv[1]);
	return solve(n);
}

#ifdef DEBUG
#define dprintf(...) printf(__VA_ARGS__)
#else
#define dprintf(...)
#endif

bool check_result(bool precond, bool success)
{
	if(precond) {
		if(!success) {
			fprintf(stderr, "Invalid result!\n");
			return false;
		}
	}
	return true;
}
