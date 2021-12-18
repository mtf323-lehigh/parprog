program simple

  implicit none
  ! required MPI include file
  include 'mpif.h'

  integer numtasks, rank, len, ierr
  character(MPI_MAX_PROCESSOR_NAME) hostname

  ! initialize MPI


  ! get number of tasks


  ! get my rank


  ! get hostname
  

  ! print task number, rank and hostname
  print '(a,i2,a,i2,a,a)', 'Number of tasks=',numtasks,' My rank=',rank,&
       ' Running on ',hostname

  ! done with MPI
  

end program simple
