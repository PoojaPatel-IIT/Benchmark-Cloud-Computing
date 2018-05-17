#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
//#define ALLOCATEDSIZE (long long)10995116277760L
#include<string.h>
#include <sys/time.h>

typedef struct dataOfthread{
short int  nt; // no. of threads
int  bz; // Block size
char struct_pattern[10];
} th_info;
// randstring function taken from :  https://codereview.stackexchange.com/questions/29198/random-string-generator-in-c
char *randstring(int length) {    
static int mySeed = 25011984;
char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
size_t stringLen = strlen(string);        
char *randomString = NULL;

srand(time(NULL) * length + ++mySeed);

if (length < 1) {
	length = 1;
}

randomString = malloc(sizeof(char) * (length +1));

if (randomString) {
	short key = 0;

	for (int n = 0;n < length;n++) {            
		key = rand() % stringLen;          
		randomString[n] = string[key];
	}

	randomString[length] = '\0';

	return randomString;        
}
else {
	printf("No memory");
	exit(1);
}
}

char *gen_str;



void *mem_fun(void *args)
{
//printf("entered mem_fun\n");
long long ALLOCATEDSIZE = 1000000000;
th_info *info;
info = (th_info*)args;
int size_of_block = info->bz;
int Num_blks = ALLOCATEDSIZE / size_of_block;
int each_threads_blcks = Num_blks / info->nt;
//	printf("accessed variables\n");
char pat[10];
strcpy(pat,info->struct_pattern);
strtok(pat,"\n");
int k;
int i;
int rand_val;
int j;
long mem= 1000000000/info->nt;
int loop = (100000000/info->nt);
if (strcmp(pat, "RWS") == 0)
{

if(size_of_block == 1 )
{
char *s= (char*)malloc(100000000/info->nt);
char *d= (char*)malloc(100000000/info->nt);
strcpy(s,gen_str);
//printf("%d\n",strlen(s));
//printf("%d\n",strlen(d));
for(i = 0; i < loop; ++i)
{
memcpy(d + i, s + i  ,size_of_block);
}
//printf("%d\n",strlen(d));
 free(s);
free(d);
}

else{

//memset(s,'F',mem);
//	puts(s);
/* char *s= (char*)malloc(250000000*sizeof(int));
char *d= (char*)malloc(250000000*sizeof(int)); */
// strncat(s, "MEMORY BENCHMARK",250000000*sizeof(char));
// printf("Sequential\n");
for(k = 0;k<100;++k)
{
char *s= (char*)malloc(mem);
char *d= (char*)malloc(mem);
strcpy(s,gen_str);
for(i = 0; i < each_threads_blcks; i = i + size_of_block)
{
memcpy(d + i, s + i,size_of_block);
}
 free(s);
 free(d);
}

}

}

else
{
if(size_of_block == 1 )
{
	//puts("here");
char *s= (char*)malloc(100000000/info->nt);
char *d= (char*)malloc(100000000/info->nt);
strcpy(s,gen_str);
//puts("allocated");
for(i = 0; i < loop; ++i)
{
rand_val = rand()%loop;
//printf("%d\n",rand_val);
memcpy(d + rand_val , s + rand_val , size_of_block);
//puts("copy done");
}
//puts("done");
 free(s);
free(d);
}
else{
	// printf("RWR latency");
for(k = 0;k<100;++k)
{		
char *s= (char*)malloc(mem);
char *d= (char*)malloc(mem);
strcpy(s,gen_str);
/* int *s= (int*)malloc(250000000*sizeof(int)); // 1000000000 / 4 = 250000000
int *d= (int*)malloc(250000000*sizeof(int)); */
//strncat(s, "MEMORY BENCHMARK",250000000*sizeof(int));
for(j = 0; j < each_threads_blcks; ++j)
{
rand_val = rand()%each_threads_blcks;
memcpy(d + rand_val, s + rand_val,size_of_block);
}
free(s);
free(d);
}

}
}
pthread_exit(NULL);

}

void mem_output_fun(char *filename,  char *mem_accesspattern,int thrdArray, int blocksize,double benchval,double th_val, double efficiency)
{
char *mem_output_filename ;

if(strcmp(filename,"memory-RWR-1-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1-4thread_out.dat";
}

else if(strcmp(filename,"memory-RWR-1000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000-4thread_out.dat";
}

else if(strcmp(filename,"memory-RWR-1000000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1000000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-1000000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-1000000-4thread_out.dat";
}

else if(strcmp(filename,"memory-RWR-10000000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-10000000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-10000000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-10000000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWR-10000000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWR-10000000-4thread_out.dat";
}

else if(strcmp(filename,"memory-RWS-1-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1-4thread_out.dat";
}


else if(strcmp(filename,"memory-RWS-1000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000-4thread_out.dat";
}



else if(strcmp(filename,"memory-RWS-1000000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1000000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-1000000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-1000000-4thread_out.dat";
}


else if(strcmp(filename,"memory-RWS-10000000-1thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-10000000-1thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-10000000-2thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-10000000-2thread_out.dat";
}
else if(strcmp(filename,"memory-RWS-10000000-4thread.dat") == 0 )
{
mem_output_filename = "memory-RWS-10000000-4thread_out.dat";
}


char mem_output_file_path[100] = "/exports/home/ppatel115/cs553-pa1/memory/output/";
//char mem_output_file_path[100] = "/home/ubuntu/cs553-pa1/memory/output/";
char *s1=mem_output_file_path;
char *s2=mem_output_filename;
strcat(s1,s2);
FILE *mem_output_filepointer = fopen (mem_output_file_path , "w" );
fprintf(mem_output_filepointer,"\nMEMORY BENCHMARK OUTPUT\n");
fprintf(mem_output_filepointer, "Workload   Concurrency  Blocksize MyRAMBenchValue   TheoreticalValue   MyRAMBenchEfficiency\n");
fprintf(mem_output_filepointer,"%s \t  \t \t %d \t  \t  \t %d \t  \t  \t %f \t  \t \t %f \t \t  \t %f \n",mem_accesspattern,thrdArray,blocksize,benchval,th_val,efficiency);
} 


int main(int argc, char **argv)
{
	
char *filename;
struct timeval start, end;

char path[155] = "/exports/home/ppatel115/cs553-pa1/memory/";
//char path[200] = "/home/ubuntu/cs553-pa1/memory/";

filename = argv[1];

char b_s[35] ;
char thrd[25]  ;

strcat(path,filename);
char file_ptrn[25]  ;
char * line = NULL;
ssize_t read;

size_t len = 0;
int i = 1;
FILE *file = fopen (path , "r" );


while ((read = getline(&line, &len, file)) != -1) 
   {   
	  if(i == 1)
	  {                 
		   strcpy(file_ptrn,line);
	  }
	  else if(i == 2)
	  {
		   strcpy(b_s,line);
	  }
	  else if(i == 3)
	  {
		   strcpy(thrd,line);
	  }
	  ++i;
   }
  
th_info info;
info.bz = atoi(b_s);
info.nt = atoi(thrd);
strcpy(info.struct_pattern,file_ptrn);
printf("\n\nExecuting Memory Benchmark\n");
//random_string()
long str = 100000000;

pthread_t threads[info.nt]; long tid; int rc;
gen_str = randstring(str/info.nt);
gettimeofday(&start, NULL);  
for (tid = 0; tid < info.nt; tid++) {
rc = pthread_create(&threads[tid], NULL, mem_fun, (void*) &info);
/* if (rc) {
printf("Could not create thread %ld\n", tid);
} */
}
for (tid = 0; tid < info.nt; tid++) {
rc = pthread_join(threads[tid], NULL);
/* if (rc) {
printf("Could not join thread %ld\n", tid);
} */
}
gettimeofday(&end, NULL);
printf("%s\n","MEMORY BENCHMARK");
printf("Workload:%s", strtok(file_ptrn,"\n"));
printf ("\t Concurrency: %s \t", strtok(thrd,"\n"));
printf("Blocksize: %d \t", info.bz);
double tot_time = (float) (end.tv_usec - start.tv_usec) / 1000000 + (float) (end.tv_sec - start.tv_sec); 
double ram_latency = tot_time/(100.00);
//double ram_latency = tot_time*1000.00;
double ram_throughput = 100.00/tot_time ;
float ram_theory_value= 2.133*2*64*2/8;
float ram_latency_value = 0.01406;
float ram_eff;
printf("Time Taken  : %fs\n",
(float) (end.tv_usec - start.tv_usec) / 1000000 +
(float) (end.tv_sec -
start.tv_sec));

if(info.bz==1){

printf("My RAM Value : %f micros\n", ram_latency);
ram_eff =  ((ram_latency - ram_latency_value) / ram_latency_value)*100 ;
mem_output_fun(argv[1],file_ptrn,info.nt, info.bz,ram_latency ,ram_latency_value,ram_eff);
printf("TheoreticalValue : %f microsec\n",ram_latency_value);
printf("Efficiency: %f \n", ram_eff);
}
else{ 
printf("MyRAMBenchValue : %f GBps\n",ram_throughput);
ram_eff= (ram_throughput / ram_theory_value )*100;
mem_output_fun(argv[1],file_ptrn,info.nt, info.bz,ram_throughput,ram_theory_value,ram_eff);	
printf("TheoreticalValue : %f GBps\n",ram_theory_value);
printf("Efficiency: %f \n", ram_eff);
}

/* if(info.bz==1)
{
mem_output_fun(argv[1],file_ptrn,info.nt, info.bz,ram_latency ,ram_theory_value,0.0);
}
else{
mem_output_fun(argv[1],file_ptrn,info.nt, info.bz,ram_throughput,ram_theory_value,0.0);	
} */


printf("Memory benchmark done \n\n\n");
} 
