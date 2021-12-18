#include "mpi.h"
#include <stdio.h>

main(int argc, char *argv[])  {
  int numtasks, rank, next, prev, buf[2], tag1=1, tag2=2;
  MPI_Request reqs[4];   // required variable for non-blocking calls
  MPI_Status stats[4];   // required variable for Waitall routine
  
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  
  // determine left and right neighbors
  prev = rank-1;
  next = rank+1;
  if (rank == 0)  prev = numtasks - 1;
  if (rank == (numtasks - 1))  next = 0;
  
  // post non-blocking receives and sends for neighbors
  // Receive 1 from left and 2 from right
  MPI_Irecv(&buf[0], 1, MPI_INT, prev, tag1, MPI_COMM_WORLD, &reqs[0]);
  MPI_Irecv(&buf[1], 1, MPI_INT, next, tag2, MPI_COMM_WORLD, &reqs[1]);
  // Send 1 to right and 2 to left
  MPI_Isend(&rank, 1, MPI_INT, prev, tag2, MPI_COMM_WORLD, &reqs[2]);
  MPI_Isend(&rank, 1, MPI_INT, next, tag1, MPI_COMM_WORLD, &reqs[3]);
  
  // wait for all non-blocking operations to complete
  MPI_Waitall(4, reqs, stats);
  
  printf("Task %d: Received from task %d with tag %d and from task %d with tag %d\n",
	 rank, prev, tag1, next, tag2);
  printf("Task %d: Send to task %d with tag %d and to task %d with tag %d\n",
	 rank, prev, tag2, next, tag1);
  
  MPI_Finalize();
}

