// required MPI include file
#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int  numtasks, rank, len, rc;
  char hostname[MPI_MAX_PROCESSOR_NAME];

  // initialize MPI
  MPI_Init(&argc,&argv);

  // get number of tasks
  MPI_Comm_size(MPI_COMM_WORLD,&numtasks);

  // get my rank
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  // get hostname
  MPI_Get_processor_name(hostname, &len);
  // print task number, rank and hostname
  printf ("Number of tasks= %d My rank= %d Running on %s\n", numtasks,rank,hostname);

  // done with MPI
  MPI_Finalize();
}
