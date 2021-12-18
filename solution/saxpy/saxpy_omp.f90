program saxpy

  implicit none
  integer :: i,n,omp_get_max_threads
  real,dimension(:),allocatable :: x, y
  real :: a,start_time, end_time

  n = 200000000
  allocate(x(n),y(n))

  !$omp parallel do default(shared) private(i)
  do i = 1, n
     x(i) = 1.0
     y(i) = 1.0
  end do
  !$omp end parallel do
  a = 2.0

  call cpu_time(start_time)
  !$omp parallel do default(shared) private(i)
  do i = 1, n
     y(i) = y(i) + a * x(i)
  end do
  !$omp end parallel do
  call cpu_time(end_time)

  deallocate(x,y)
  
  print '(a,i3,2x,a,f8.6)', 'Threads: ', omp_get_max_threads(), &
         'SAXPY Time: ', end_time - start_time
  
end program saxpy
    
