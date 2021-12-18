program hello

  implicit none
  integer :: omp_get_thread_num, omp_get_num_threads

  !$omp parallel
  print '(a,i3,a,i3,a)', 'Hello from thread', omp_get_thread_num, 'out of ', omp_get_num_threads
  !$omp end parallel

end program hello
