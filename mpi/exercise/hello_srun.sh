mpicc -o helloc hello.c
srun -p lts -n 4 -N 4 -t 10 ./helloc
