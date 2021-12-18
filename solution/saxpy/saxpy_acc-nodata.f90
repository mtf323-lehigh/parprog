program saxpy

  implicit none
  integer :: i,n
  real,dimension(:),allocatable :: x, y
  real :: a,start_time, end_time

  n = 200000000
  allocate(x(n),y(n))

  !$acc parallel loop
  do i = 1, n
     x(i) = 1.0
     y(i) = 1.0
  end do
  !$acc end parallel loop
  a = 2.0

  call cpu_time(start_time)
  !$acc parallel loop
  do i = 1, n
     y(i) = y(i) + a * x(i)
  end do
  !$acc end parallel loop
  call cpu_time(end_time)
  deallocate(x,y)
  
  print '(a,f8.6)', 'SAXPY Time: ', end_time - start_time
  
end program saxpy
    
