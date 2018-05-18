CC = gcc
CFLAGS = -Wall -lpthread 
run1 = sbatch jobtestmemRWS.slurm
run2 = sbatch jobtestmemRWR.slurm
# run2 = sbatch jobtest_RWS.slurm
# run3 = sbatch jobtest_RWR_RWSlatency.slurm

mem1:
	gcc  -o main.exe MyRAMBench.c -lpthread
	$(run1)
mem2:
	gcc  -o main.exe MyRAMBench.c -lpthread
	$(run2)
# mem3:
	# gcc  -o main.exe MyRAMBench.c -lpthread
	# $(run3)


clean:
	rm -rf *.o MyRAMBench

all: clean
	$(CC) $(CFLAGS) -pthread MyRAMBench.c -o MyRAMBench

