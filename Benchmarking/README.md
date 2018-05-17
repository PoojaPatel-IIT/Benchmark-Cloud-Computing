BENCHMARKING:

A20396099
Pooja Hemantkumar Patel

	
1.CPU

	a. Login to Hyperion
	b. Navigate to cpu folder
	c. type following command:
	
		i. make cpu1

		(Note : This will run all "SP" and output will be in the output folder and also in cpuSP.out)
	
		ii.make cpu2 
	
		(Note : This will run all "QP" and output will be in the output folder or in cpuQP.out)

		iii. make cpu3 
		
		(Note : This will run all "HP" and output will be in the output folder or in cpuHP.out)
	
		iv. make cpu4 
		
		(Note : This will run all "DP" and output will be in the output folder or in cpuDP.out)
		
		
2.MEMORY 

	a. Login to Hyperion
	b. Navigate to memory folder
	c. type following command:
	
		i. make mem1

		(Note : This will run all RWS and output will be in the output folder and also in mem_RWS.out)
	
		i. make mem2

		(Note : This will run all RWR and output will be in the output folder and also in mem_RWR.out)
		
3. DISK 


	a. Login to Prometheus 
	b. Navigate to disk folder
	c. type following command:
	
		i. make disk1

		(Note : This will run for few access patterns (see .slurm for details) and output will be in the output folder and also in main1.out)
	
		ii. make disk2

		(Note : This will run for few access patterns (see .slurm for details) and output will be in the output folder and also in main2.out)
		
		iii. make disk3

		(Note : This will run for few access patterns (see .slurm for details) and output will be in the output folder and also in main1.out)
	
		iv. make disk4

		(Note : This will run for few access patterns (see .slurm for details) and output will be in the output folder and also in main1.out)
		
		.
		.
		.
		.
		.
		.
		
		v. so on till "make disk26"
	
