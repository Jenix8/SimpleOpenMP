#include <iostream>
#include <omp.h>
#include <time.h>

int main() {
	// OpenMP, Critical section
	// Goal : count 1e11 in 1s

	clock_t S = clock();

	//int max_thread = omp_get_max_threads();

	unsigned long long int count = 0;
	long long int limit = 1e10;
	
#pragma omp parallel for reduction(+:count) //, schedule(static)
	for (long long int i = 0; i < limit; i += 1)
	{
		count += i / 10;
	}

	printf("%lld\n", count);
	std::cout << (clock() - S) / 1000.f << 's' << '\n';

	return 0;
}