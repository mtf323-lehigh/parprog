// required MPI include file
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int  numtasks, rank, len, rc;
  char hostname[MPI_MAX_PROCESSOR_NAME];
  int ver, subver;

  // initialize MPI
  MPI_Init(&argc,&argv);

  // get number of tasks
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

  // get my rank
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  // print hostname if rank is odd and mpi version if rank is even
  if ( rank % 2 == 1  ) {
    MPI_Get_processor_name(hostname, &len);
    printf ("Number of tasks= %d My rank= %d Running on %s\n", numtasks,rank,hostname);
  } else {
    MPI_Get_version(&ver, &subver);
    printf ("Number of tasks= %d My rank= %d MPI version:  %d . %d \n",numtasks,rank,ver,subver);
  }
  // done with MPI
  MPI_Finalize();
}
