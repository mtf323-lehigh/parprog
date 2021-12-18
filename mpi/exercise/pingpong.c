#include "mpi.h"
#include <stdio.h>

main(int argc, char *argv[])  {
  int numtasks, rank, dest, source, rc, count, tag=1;  
  char inmsg, outmsg='x';
  MPI_Status Stat;   // required variable for receive routines
  
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  count = 1;
  tag = 1;
  
  // task 0 sends to task 1 and waits to receive a return message
  if (rank == 0) {
    dest = 1;
    source = 1;
  } 
  
  // task 1 waits for task 0 message then returns a message
  else if (rank == 1) {
    dest = 0;
    source = 0;
  }

  // send/receive messages!
  MPI_Send(&outmsg, count, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
  MPI_Recv(&inmsg, count, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
  
  // query recieve Stat variable and print message details

  printf("Task %d: Received %d char(s) from task %d with tag %d \n"
	 "Message: %c \n",
	 rank, count, Stat.MPI_SOURCE, Stat.MPI_TAG, inmsg);
  
  MPI_Finalize();
}
