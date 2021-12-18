#include <stdio.h>
#include <time.h>
#include <omp.h>

#define n 200000000

double x[n], y[n];

int main() {
  int i;
  float a=2.0;
  double start_time, end_time;
	
#pragma acc kernels loop
  for (i = 0; i < n; i++){
    x[i] = 1.0;
    y[i] = 2.0;
  }

  start_time = omp_get_wtime();
#pragma acc kernels loop
  for (i = 0; i < n; i++){
    y[i] = a*x[i] + y[i];
  }
  end_time = omp_get_wtime();
  printf ("SAXPY Time: %8.6f\n", end_time - start_time);
}

