#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
  long long int i, n=100000000;
  double start_time, end_time;
  double x, pi;
  double sum = 0.0;
  double step = 1.0/(double) n; 

#pragma acc data copyin(step) copyout(sum)
  {
    start_time = omp_get_wtime();
#pragma acc parallel loop private(i,x) reduction(+:sum)
    {
      for (i = 0; i < n; i++) {
	x = (i+0.5)*step;
	sum +=  4.0/(1.0+x*x);
      }
    }
  }
  pi = step * sum;
  end_time = omp_get_wtime();

  printf("pi = %17.15f\n",pi);
  printf("time to compute = %g seconds\n", (double)(end_time - start_time));
  return 0;
}
