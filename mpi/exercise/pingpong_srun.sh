mpicc -o pingpong pingpong.c
srun -p lts -n 2 -N 2 -t 10 ./pingpong
