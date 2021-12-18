#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char* argv[]) {
  long long int i, n=100000000;
  double start_time, end_time;
  double x, pi;
  double sum = 0.0, result = 0.0;
  double step = 1.0/(double) n; 
  int rank, size;
	
  /* Initialize MPI */
  MPI_Init(&argc, &argv);
	
  /* Get my process ID number */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
  /* Get my process number */
  MPI_Comm_size (MPI_COMM_WORLD, &size);
	
  /* Start timer only on main */
  if ( rank == 0)  
    start_time = MPI_Wtime();
 
  /* Broadcast value of n to all processes */
  MPI_Bcast(&n,1,MPI_INTEGER,0,MPI_COMM_WORLD);

  /* Divide work such that each process gets n/n_p elements to calculate */ 
  for (i = rank*n/size ; i < (rank + 1)*n/size ; i++ ) {
    x = (i+0.5)*step;
    result +=  4.0/(1.0+x*x);
  }
	
  /* collect all partial results with a reduction operation */
  MPI_Reduce(&result, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

  /* Synchronize all processes */
  MPI_Barrier(MPI_COMM_WORLD);

  /* Calculate value of pi and stop timer if main process */	
  if ( rank == 0) {
    end_time = MPI_Wtime();
    pi = step * sum;
    printf("pi = %17.15f\n",pi);
    printf("time to compute = %g seconds\n", (double)(end_time - start_time));
  }
	
  /* Finalize MPI */
  MPI_Finalize();
	
  return 0;
}
