nvcc -o saxpy saxpy.cu
srun -p hawkgpu -n 1 -N 1 -t 10 --gres=gpu:1 -A hpc2021_prog_083121 --reservation=lts_165 ./saxpy