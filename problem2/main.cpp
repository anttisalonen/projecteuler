#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	unsigned int new_fib = 2;
	unsigned int old_fib = 1;
	unsigned int older_fib = 1;
	unsigned int n = atoi(argv[1]);
	unsigned int sum = 0;
	while(1) {
		new_fib = old_fib + older_fib;
		old_fib = older_fib;
		older_fib = new_fib;
		if(new_fib >= n)
			break;
		if(new_fib % 2 == 0) {
			sum += new_fib;
		}
		printf("%u ", new_fib);
	}
	printf("\n%u\n", sum);
}
