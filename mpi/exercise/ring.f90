program ringtopo
  include 'mpif.h'
  
  integer numtasks, rank, next, prev, buf(2), tag1, tag2, ierr, count
  integer reqs(4)   ! required variable for non-blocking calls 
  integer stats(MPI_STATUS_SIZE,4)   ! required variable for WAITALL routine 
  tag1 = 1
  tag2 = 2
  
  call MPI_INIT(ierr)
  call MPI_COMM_RANK(MPI_COMM_WORLD, rank, ierr)
  call MPI_COMM_SIZE(MPI_COMM_WORLD, numtasks, ierr)
  
  ! determine left and right neighbors 
  prev = rank - 1
  next = rank + 1
  if (rank .eq. 0) then
     prev = numtasks - 1
  endif
  if (rank .eq. numtasks - 1) then
     next = 0
  endif
  
  ! post non-blocking receives and sends for neighbors 
  ! Receive 1 from left and 2 from right


  ! Send 1 to right and 2 to left


  
  ! wait for all non-blocking operations to complete 

  
  print '(5(a,i2))',  'Task ',rank,': Received from task', prev, ' with tag',tag1, &
       ' and from task', next, ' with tag',tag2
  print '(5(a,i2))',  'Task ',rank,': Send to task', prev, ' with tag',tag2, &
       ' and to task', next, ' with tag',tag1

  ! continue - do more work
  
  call MPI_FINALIZE(ierr)
  
end program ringtopo
