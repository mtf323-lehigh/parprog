program simple

  implicit none
  ! required MPI include file
  include 'mpif.h'

  integer:: numtasks, rank, len, ierr
  character(len=MPI_MAX_PROCESSOR_NAME):: hostname
  integer :: mpi_ver, mpi_subver

  ! initialize MPI
  call MPI_INIT(ierr)

  ! get number of tasks
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)

  ! get my rank
  call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)

  ! print hostname if rank is odd and mpi version if rank is even
  if (mod(rank,2) == 0 ) then 
     call MPI_Get_version(mpi_ver, mpi_subver, ierr)
     print '(a,i1,a,i1)', 'MPI version is ', mpi_ver, '.', mpi_subver
     print '(a,i2,a,i2,a,i1,a,i1)', 'Number of tasks=',numtasks,' My rank=',rank,&
          ' MPI version:' , mpi_ver, '.', mpi_subver
  else
     call MPI_GET_PROCESSOR_NAME(hostname, len, ierr)
     print '(a,i2,a,i2,a,a)', 'Number of tasks=',numtasks,' My rank=',rank,&
          ' Running on ',hostname
  end if
  
  ! done with MPI
  call MPI_FINALIZE(ierr)


end program simple
