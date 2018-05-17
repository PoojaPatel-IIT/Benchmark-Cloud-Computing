CC = gcc
CFLAGS = -Wall -lpthread 
run1 = sbatch jobtest1.slurm
run2 = sbatch jobtest2.slurm
run3 = sbatch jobtest3.slurm
run4 = sbatch jobtest4.slurm
run5 = sbatch jobtest5.slurm
run6 = sbatch jobtest6.slurm
run7 = sbatch jobtest7.slurm
run8 = sbatch jobtest8.slurm
run9 = sbatch jobtest9.slurm
run10 = sbatch jobtest10.slurm
run11 = sbatch jobtest11.slurm
run12 = sbatch jobtest12.slurm
run13 = sbatch jobtest13.slurm
run14 = sbatch jobtest14.slurm
run15 = sbatch jobtest15.slurm
run16 = sbatch jobtest16.slurm
run17 = sbatch jobtest17.slurm
run18 = sbatch jobtest18.slurm
run19 = sbatch jobtest19.slurm
run20 = sbatch jobtest20.slurm
run21 = sbatch jobtest21.slurm
run22 = sbatch jobtest22.slurm
run23 = sbatch jobtest23.slurm
run24= sbatch jobtest24.slurm
run25= sbatch jobtest25.slurm
run26= sbatch jobtest26.slurm
disk1:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run1)
disk2:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run2)
disk3:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run3)
disk4:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run4)
disk5:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run5)
disk6:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run6)
disk7:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run7)
disk8:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run8)
disk9:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run9)
disk10:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run10)
disk11:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run11)
disk12:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run12)
disk13:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run13)
disk14:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run14)
disk15:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run15)
disk16:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run16)
disk17:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run17)
disk18:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run18)
disk19:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run19)
disk20:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run20)
disk21:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run21)
disk22:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run22)
disk23:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run23)
disk24:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run24)
disk25:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run25)
disk26:
	gcc  -o main.exe MyDiskBench.c -lpthread
	$(run26)

	

clean:
	rm -rf *.o MyDiskBench

all: clean
	$(CC) $(CFLAGS) -pthread MyDiskBench.c -o MyDiskBench

