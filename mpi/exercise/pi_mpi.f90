program pi_mpi

  use mpi

  implicit none
  integer, parameter :: dp=selected_real_kind(14)
  integer :: i, ierr, nproc, myrank, istart, iend
  integer, parameter :: n=100000000
  real(dp) :: x,pi,sum,total_sum, step,start_time,end_time
  
  
  ! MPI Calls
  ! Initialize MPI
  call MPI_INIT(ierr)
  ! Get Process ID
  call MPI_COMM_RANK(MPI_COMM_WORLD,myrank,ierr)
  ! Get Process number
  call MPI_COMM_SIZE(MPI_COMM_WORLD,nproc,ierr)

  sum = 0d0
  step = 1.d0/real(n,kind=dp)

  ! Start timer only on main
  if (myrank == 0 ) then
     start_time = MPI_WTIME();
  end if
  
  ! Broadcast value of n to all processes, not sure why this gives a seg fault
  !call MPI_BCAST(n,1,MPI_INTEGER,0,MPI_COMM_WORLD,ierr)
  
  ! Divide work such that each process gets n/n_p elements to calculate
  do i = myrank+1, n, nproc
     x = (real(i) + 0.5d0) * step
     sum = sum + 4.d0 / (1.d0 + x ** 2)
  end do

  ! collect all partial results with a reduction operation
  

  ! Synchronize all processes
  

  ! Calculate value of pi and stop timer if main process
  if (myrank == 0) then
     end_time = MPI_WTIME();
     pi = step * total_sum
     print '(a,f17.15)', "pi = ", pi
     print '(a,f9.3,a)', "time to compute =",end_time - start_time, " seconds"
  end if
  
  ! Finalize MPI
  call MPI_FINALIZE(ierr)
  
end program pi_mpi
