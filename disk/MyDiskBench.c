#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
//#define ALLOCATEDSIZE 1000
#include<string.h>
#include <sys/time.h>

typedef struct dataOfthread{
int   nt; // no. of threads
int  bz; // Block size
char struct_pattern[10];
} th_info;

FILE *funOpenDiskBM_10GBFile(char *nameOfTheFileToOpen,char *filemode)
{		
	FILE *pointFileRead = fopen( nameOfTheFileToOpen, filemode);
}

void *disk_fun(void *args)
{
//printf("entered disk_fun\n");
//printf("1-Allocated 10 GB");
long long ALLOCATEDSIZE = 10000000000L;
int s = 1000;
//printf("2-Allocated 10 GB\n");
th_info *info;
info = (th_info*)args;
int size_of_block = info->bz * 1000;
long Num_blks = 10000000000 / size_of_block;
int each_threads_blcks = Num_blks / info->nt;
//printf("accessed variables\n");
char pat[10];
strcpy(pat,info->struct_pattern);
strtok(pat,"\n");
int i;
char *insidefile = (char *) malloc(size_of_block);
	// printf("accessed pooja\n");

if (strcmp(pat, "RS") == 0)
{
char file10GB[]="/tmp/DiskBM_10GBFile.txt";
FILE *pointFileRead=  funOpenDiskBM_10GBFile (file10GB , "r");


for(i = 0; i < each_threads_blcks; ++i)
{
	fread(insidefile,size_of_block,1 , pointFileRead);
}
fclose(pointFileRead);
}


else if (strcmp(pat, "WS") == 0)
{
//char file10GB[]="cs553-pa1/disk/DiskBM_10GBFile.txt";
FILE *pointFileRead=  funOpenDiskBM_10GBFile ("/tmp/DiskBM_10GBFile.txt" , "a+");
//char insidefile[ALLOCATEDSIZE];


for(i = 0; i < each_threads_blcks; ++i)
{
	fwrite(insidefile,1,size_of_block , pointFileRead);
}
fclose(pointFileRead);
}


else if (strcmp(pat, "RR") == 0)
{
//char file10GB[]="cs553-pa1/disk/DiskBM_10GBFile.txt";
FILE *pointFileRead=  funOpenDiskBM_10GBFile ("/tmp/DiskBM_10GBFile.txt" , "r");
//char insidefile[ALLOCATEDSIZE];
if (size_of_block==1000)
{
	int loop = 1000000/each_threads_blcks;
for(i = 0; i < loop ; ++i)
{
 fseek (pointFileRead,rand()%each_threads_blcks, SEEK_CUR);
fread(insidefile,size_of_block,1 , pointFileRead);
}

fclose(pointFileRead);
}

else 
{
	
	for(i = 0; i < each_threads_blcks; ++i)
{
 fseek (pointFileRead,rand()%each_threads_blcks, SEEK_CUR);
fread(insidefile,size_of_block,1 , pointFileRead);
}
fclose(pointFileRead);
}

}


else if (strcmp(pat, "WR") == 0)
{
//char file10GB[]="cs553-pa1/disk/DiskBM_10GBFile.txt";
FILE *pointFileRead=  funOpenDiskBM_10GBFile ("/tmp/DiskBM_10GBFile.txt" , "a+");
if(size_of_block==1000){
	int loop = 1000000/each_threads_blcks;
	for(i = 0; i < loop ; ++i)
{
fseek (pointFileRead,rand()%each_threads_blcks, SEEK_SET);
fwrite(insidefile,size_of_block,1 , pointFileRead);
}
fclose(pointFileRead);		
}

else
{

for(i = 0; i < each_threads_blcks; ++i)
{
	 fseek (pointFileRead,rand()%each_threads_blcks, SEEK_SET);
fwrite(insidefile,size_of_block,1 , pointFileRead);
}
fclose(pointFileRead);
}

}

pthread_exit(NULL);

}
void disk_output_fun(char *filename,  char *disk_pattern,int thrdArray, int blocksize,double benchval,double th_val, double efficiency)
{
char *disk_output_filename ;

if(strcmp(filename,"disk-RR-1-1thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-1thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-2thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-2thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-4thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-4thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-8thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-8thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-16thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-16thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-32thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-32thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-64thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-64thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1-128thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1-128thread_out.dat";
}


else if(strcmp(filename,"disk-WR-1-1thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-1thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-2thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-2thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-4thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-4thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-8thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-8thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-16thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-16thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-32thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-32thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-64thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-64thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1-128thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1-128thread_out.dat";
}


else if(strcmp(filename,"disk-WR-1000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WR-1000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WR-1000-4thread_out.dat";
}



else if(strcmp(filename,"disk-RR-1000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RR-1000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RR-1000-4thread_out.dat";
}


else if(strcmp(filename,"disk-WR-10000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WR-10000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WR-10000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WR-10000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WR-10000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WR-10000-4thread_out.dat";
}



else if(strcmp(filename,"disk-RR-10000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RR-10000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RR-10000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RR-10000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RR-10000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RR-10000-4thread_out.dat";
}


else if(strcmp(filename,"disk-WR-100000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WR-100000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WR-100000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WR-100000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WR-100000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WR-100000-4thread_out.dat";
}



else if(strcmp(filename,"disk-RR-100000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RR-100000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RR-100000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RR-100000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RR-100000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RR-100000-4thread_out.dat";
}



else if(strcmp(filename,"disk-RS-1000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RS-1000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RS-1000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RS-1000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RS-1000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RS-1000-4thread_out.dat";
}



else if(strcmp(filename,"disk-WS-1000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WS-1000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WS-1000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WS-1000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WS-1000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WS-1000-4thread_out.dat";
}

else if(strcmp(filename,"disk-RS-10000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RS-10000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RS-10000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RS-10000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RS-10000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RS-10000-4thread_out.dat";
}



else if(strcmp(filename,"disk-WS-10000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WS-10000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WS-10000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WS-10000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WS-10000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WS-10000-4thread_out.dat";
}


else if(strcmp(filename,"disk-RS-100000-1thread.dat") == 0 )
{
disk_output_filename = "disk-RS-100000-1thread_out.dat";
}
else if (strcmp (filename,"disk-RS-100000-2thread.dat") == 0 )
{
disk_output_filename = "disk-RS-100000-2thread_out.dat";
}
else if (strcmp (filename,"disk-RS-100000-4thread.dat") == 0 )
{
disk_output_filename = "disk-RS-100000-4thread_out.dat";
}



else if(strcmp(filename,"disk-WS-100000-1thread.dat") == 0 )
{
disk_output_filename = "disk-WS-100000-1thread_out.dat";
}
else if (strcmp (filename,"disk-WS-100000-2thread.dat") == 0 )
{
disk_output_filename = "disk-WS-100000-2thread_out.dat";
}
else if (strcmp (filename,"disk-WS-100000-4thread.dat") == 0 )
{
disk_output_filename = "disk-WS-100000-4thread_out.dat";
}



char disk_output_file_path[100] = "/exports/home/ppatel115/cs553-pa1/disk/output/";
//char disk_output_file_path[100] = "/home/ubuntu/";
//char op_path[100] = "/home/ubuntu/cs553-pa1/cpu/output/";
char *s1=disk_output_file_path;
char *s2=disk_output_filename;
strcat(s1,s2);
FILE *disk_output_filepointer = fopen (disk_output_file_path , "w" );
fprintf(disk_output_filepointer,"\nDISK BENCHMARK OUTPUT\n");
fprintf(disk_output_filepointer, "Workload   Concurrency  Blocksize  MyDiskBenchValue   TheoreticalValue   MyDiskBenchEfficiency\n");
fprintf(disk_output_filepointer,"%s \t  \t \t %d \t  \t  \t %d \t  \t  \t  %f \t  \t \t %f \t \t  \t %f \n",disk_pattern,thrdArray,blocksize,benchval,th_val,efficiency);
} 
// link : https://stackoverflow.com/questions/15767691/whats-the-c-library-function-to-generate-random-string
void rand_str(char *dest, size_t length) {
char charset[] = "9999999999"
				 "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				 "abcdefghijklmnopqrstuvwxyz";
while (length-- > 0) {
	size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
	*dest++ = charset[index];
}
*dest = '\0';
}

void *make_10GB_file(void *args)
{	long f;
//puts("starting...");
 char inside10GBfile[1000000] ;
 rand_str(inside10GBfile,(1000000-1));

long loop=1000;
FILE *file_10GB_pointer = fopen("/tmp/DiskBM_10GBFile.txt","a+");    
for(f=0;f<loop;f++)
{
	
	fwrite(inside10GBfile,1000000,1,file_10GB_pointer);
}
}
int main(int argc, char **argv)
{
char *filename;
char path[150] = "/exports/home/ppatel115/cs553-pa1/disk/";
//char path[150] = "/home/ubuntu/";
// printf("%d\n",sizeof(int));
if(argc > 1)
{
filename = argv[1];
}
strcat(path,filename);
int rc;
char * line = NULL;
char thrd[10]  ;
char b_s[20] ;
size_t len = 0;
char file_ptrn[10]  ;


ssize_t read;
FILE *file = fopen (path , "r" );
int i = 1;

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
 strtok(file_ptrn,"\n");
if(strcmp(file_ptrn,"RS")==0|| strcmp(file_ptrn,"RR")==0 )	
{

/*creating file*/
pthread_t threadforfile[10]; 
//printf("thread");
long idforthread; 
//printf("tid"); 

for (idforthread = 0; idforthread < 10; idforthread++) {
rc = pthread_create(&threadforfile[idforthread], NULL, make_10GB_file, NULL);

/* if (rc) {
printf("Not able to create threads %ld\n", idforthread);
} */
}
for (idforthread = 0; idforthread < 10; idforthread++) {
rc = pthread_join(threadforfile[idforthread], NULL);
/* if (rc) {
printf("Not able to join threads %ld\n", idforthread);
} */
}
/*end of file create*/ 
}	  
th_info info;
info.bz = atoi(b_s);
info.nt = atoi(thrd);
int t = info.nt;

strcpy(info.struct_pattern,file_ptrn);
printf("Executing Disk Benchmark\n");

pthread_t threads[info.nt]; 
long tid; 
struct timeval start, end;
gettimeofday(&start, NULL); 
for (tid = 0; tid < info.nt; tid++) {
rc = pthread_create(&threads[tid], NULL, disk_fun, (void*) &info);
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
printf("%s\n","DISK BENCHMARK ");
printf ("\t Concurrency: %s \t", strtok(thrd,"\n"));
printf("Workload: %s", strtok(file_ptrn,"\n"));
printf ("\t Block size: %s \t", strtok(b_s,"\n"));



double disk_total_time=(float) (end.tv_usec - start.tv_usec) / 1000000 +
(float) (end.tv_sec -
start.tv_sec);

if(info.bz==1){
  
printf("Disk benchmark time taken  : %f ms\n",disk_total_time);
}

else{

printf("MyDiskBenchValue : %f MBps\n",(10*1000)/disk_total_time);
}


if(info.bz==1){
  disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,disk_total_time ,0.0,0.0);
}
else{
if (strcmp(file_ptrn,"RR")==0  && info.nt == 1){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,372.00, (10*1000*100)/disk_total_time/372.00 );
}
else if (strcmp(file_ptrn,"RR")==0  && info.nt == 2){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,372.00*2, (10*1000*100)/disk_total_time/(372.00*2) );
}
else if (strcmp(file_ptrn,"RR")==0  && info.nt == 4){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,372.00*4, (10*1000*100)/disk_total_time/(372.00*4) );
}

else if (strcmp(file_ptrn,"WR")==0  && info.nt == 1){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,172.00, (10*1000*100)/disk_total_time/172.00 );
}
else if (strcmp(file_ptrn,"WR")==0  && info.nt == 2){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,172.00*2, (10*1000*100)/disk_total_time/(172.00*2) );
}
else if (strcmp(file_ptrn,"WR")==0  && info.nt == 4){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,172.00*4, (10*1000*100)/disk_total_time/(172.00*4) );
}


else if (strcmp(file_ptrn,"WS")==0  && info.nt == 1){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,410.00, (10*1000*100)/disk_total_time/410.00 );
}
else if (strcmp(file_ptrn,"WS")==0  && info.nt == 2){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,410.00*2, (10*1000*100)/disk_total_time/(410.00*2) );
}
else if (strcmp(file_ptrn,"WS")==0  && info.nt == 4){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,410.00*4, (10*1000*100)/disk_total_time/(410.00*4) );
}

else if (strcmp(file_ptrn,"RS")==0  && info.nt == 1){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,540.00, (10*1000*100)/disk_total_time/540.00 );
}
else if (strcmp(file_ptrn,"RS")==0  && info.nt == 2){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,540.00*2, (10*1000*100)/disk_total_time/(540.00*2) );
}
else if (strcmp(file_ptrn,"RS")==0  && info.nt == 4){
disk_output_fun(argv[1],file_ptrn,info.nt,info.bz,(10*1000)/disk_total_time,540.00*4, (10*1000*100)/disk_total_time/(540.00*4) );
}



}

char filetobedeleted[30]= "/tmp/DiskBM_10GBFile.txt";
int deletefile = remove(filetobedeleted);
/* if (deletefile == 0)
  printf("%s file deletion success .\n", filetobedeleted);
else
{
  printf("File deletion failure\n");
} */


} 