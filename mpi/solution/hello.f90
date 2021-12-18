program simple

  implicit none
  ! required MPI include file
  include 'mpif.h'

  integer numtasks, rank, len, ierr
  character(MPI_MAX_PROCESSOR_NAME) hostname

  ! initialize MPI
  call MPI_INIT(ierr)

  ! get number of tasks
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)

  ! get my rank
  call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)

  ! get hostanme
  call MPI_GET_PROCESSOR_NAME(hostname, len, ierr)

  ! print task number, rank and hostname
  print '(a,i2,a,i2,a,a)', 'Number of tasks=',numtasks,' My rank=',rank,&
       ' Running on ',hostname

  ! done with MPI
  call MPI_FINALIZE(ierr)

end program simple
