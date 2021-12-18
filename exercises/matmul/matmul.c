#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dt(start, end)  ((end.tv_sec - start.tv_sec) + \
			 1/1000000.0*(end.tv_usec - start.tv_usec))

/*
  define rows and columns of matrices a, b and c
 a[nra,nca], b[nca,ncb], c[nra, ncb]
*/

#define nra 1500
#define nca 2000
#define ncb 1000

double a[nra][nca], b[nca][ncb], c[nra][ncb]; 

int main() {
  int i,j,k;
  struct timeval icalc, scalc, ecalc;
  double flops, sum, timing ;
  
  flops = 2.0 * nra * nca * ncb;

  gettimeofday(&icalc, NULL);
  for (i = 0; i < nra; i++){
    for (j = 0; j < nca; j++){
      a[i][j] = (double)(i+j);
    }
  }
  for (j = 0; j < nca; j++){
    for (k = 0; k < ncb; k++){
      b[j][k] = (double)(i*j);
    }
  }
  for (i = 0; i < nra; i++){
    for (k = 0; k < ncb; k++){
      c[i][k] = 0.0;
    }
  }
  
  gettimeofday(&scalc, NULL);
  /* Parallelize the following block of code */
  for (i = 0; i < nra; i++){
    for (k = 0; k < ncb; k++){
      sum = 0.0;
      for (j = 0; j < nca; j++){
	sum = sum + a[i][j] * b[j][k];
      }
      c[i][k] = sum;
    }
  }
  gettimeofday(&ecalc, NULL);

  timing = dt(scalc,ecalc);
  printf("Init Time: %6.3f Calc Time: %6.3f GFlops: %7.3f\n",dt(icalc,scalc),timing,1e-9*flops/timing );
}
