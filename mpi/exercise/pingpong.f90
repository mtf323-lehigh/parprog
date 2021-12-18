program ping
  include 'mpif.h'

  integer :: numtasks, rank, dest, source, count, tag, ierr
  integer :: stat(MPI_STATUS_SIZE)   ! required variable for receive routines
  character :: inmsg, outmsg
  outmsg = 'x'
  tag = 1
  
  call MPI_INIT(ierr)
  call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)
  
  ! task 0 sends to task 1 and waits to receive a return message
  if (rank .eq. 0) then
     dest = 1
     source = 1


     
     ! task 1 waits for task 0 message then returns a message
  else if (rank .eq. 1) then
     dest = 0
     source = 0


  endif
  
  ! query recieve Stat variable and print message details

  print '(4(a,i3,1x))', 'Task ',rank,': Received', count, ' char(s) from task', &
       stat(MPI_SOURCE), 'with tag',stat(MPI_TAG)
  
  call MPI_FINALIZE(ierr)
  
end program ping
