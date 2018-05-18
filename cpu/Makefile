CC = gcc
CFLAGS = -Wall -lpthread 
run1 = sbatch jobtestcpuSP.slurm
run2 = sbatch jobtestcpuQP.slurm
run3 = sbatch jobtestcpuHP.slurm
run4 = sbatch jobtestcpuDP.slurm

cpu1:
	gcc  -o main.exe MyCPUBench.c -lpthread
	$(run1)
cpu2:
	gcc  -o main.exe MyCPUBench.c -lpthread
	$(run2)
cpu3:
	gcc  -o main.exe MyCPUBench.c -lpthread
	$(run3)
cpu4:
	gcc  -o main.exe MyCPUBench.c -lpthread
	$(run4)

clean:
	rm -rf *.o MyCPUBench

all: clean
	$(CC) $(CFLAGS) -pthread MyCPUBench.c -o MyCPUBench

