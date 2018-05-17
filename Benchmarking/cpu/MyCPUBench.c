#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include <dirent.h>
#include<string.h>
#include <sys/time.h>

typedef struct dataOfthread{
short int  nt; // no. of thrdArray
char cpu_prec[10];
} th_info;

void *dp_4trd(void *args)
{
long c=0;
int i,j;
int no_trd = 4;
double mat1[3][3]= { {1.33,2.12,3.11},{1.33,2.12,3.11},{1.33,2.12,3.11}};
//double mat2[3][3]= { {1.33,2.12,3.11},{1.33,2.12,3.11},{1.33,2.12,3.11}};
//double add[3][3];
long itr= 16666666667/no_trd; // 1 trillion divided by 60
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1.00;
	mat1[i][j] + 2.00;
	mat1[i][j] + 3.00;
	mat1[i][j] + 4.00;
	mat1[i][j] + 5.00;
	mat1[i][j] + 6.00;
  }
  
  }	
  c++;
 // fflush(stdin);
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *dp_2trd(void *args)
{
long c=0;
int i,j;
int no_trd = 2;
double mat1[3][3]= { {1.33,2.12,3.11},{1.33,2.12,3.11},{1.33,2.12,3.11}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1.00;
	mat1[i][j] + 2.00;
	mat1[i][j] + 3.00;
	mat1[i][j] + 4.00;
	mat1[i][j] + 5.00;
	mat1[i][j] + 6.00;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *dp_1trd(void *args)
{
long c=0;
int i,j;
int no_trd = 1;
double mat1[3][3]= { {1.33,2.12,3.11},{1.33,2.12,3.11},{1.33,2.12,3.11}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1.00;
	mat1[i][j] + 2.00;
	mat1[i][j] + 3.00;
	mat1[i][j] + 4.00;
	mat1[i][j] + 5.00;
	mat1[i][j] + 6.00;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *sp_4trd(void *args)
{
long c=0;
int i,j;
int no_trd = 4;
int mat1[3][3]= { {1,2,3},{1,2,3},{1,2,3}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *sp_2trd(void *args)
{
long c=0;
int i,j;
int no_trd = 2;
int mat1[3][3]= { {1,2,3},{1,2,3},{1,2,3}};
long itr= 16666666667/no_trd;

while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}


void *sp_1trd(void *args)
{
long c=0;
int i,j;
int no_trd = 1;
int mat1[3][3]= { {1,2,3},{1,2,3},{1,2,3}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
  pthread_exit(NULL);
}


void *hp_4trd(void *args)
{
long c=0;
int i,j;
int no_trd = 4;
short mat1[3][3]= { {1,2,3},{1,2,3},{1,2,3}};
long itr= 16666666667/no_trd;
//printf("Here");
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
  pthread_exit(NULL);
}
void *hp_2trd(void *args)
{
long c=0;
int i,j;
int no_trd = 2;
short int mat1[3][3]= { {16,28,32},{31,26,37},{31,52,73}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *hp_1trd(void *args)
{
long c=0;
int i,j;
int no_trd = 1;
short int mat1[3][3]= { {12,52,53},{51,62,73},{21,32,63}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}

void *qp_4trd(void *args)
{
long c=0;
int i,j;
int no_trd = 4;
char mat1[3][3]= { {'a','b','c'},{'a','b','c'},{'a','b','c'}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
  pthread_exit(NULL);
}
void *qp_2trd(void *args)
{
long c=0;
int i,j;
int no_trd = 2;
char mat1[3][3]= { {'a','b','c'},{'a','b','c'},{'a','b','c'}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1;
	mat1[i][j] + 2;
	mat1[i][j] + 3;
	mat1[i][j] + 4;
	mat1[i][j] + 5;
	mat1[i][j] + 6;
  }
  
  }	
  c++;
}
  pthread_exit(NULL);
}
void *qp_1trd(void *args)
{
long c=0;
int i,j;
int no_trd = 1;
char mat1[3][3]= { {'a','b','c'},{'a','b','c'},{'a','b','c'}};
long itr= 16666666667/no_trd;
while (c <  itr)
{
  for (i=0 ; i<3 ;i ++)
  {
	 for (j=0 ; j<3 ; j ++)
  {
	mat1[i][j] + 1.00;
	mat1[i][j] + 2.00;
	mat1[i][j] + 3.00;
	mat1[i][j] + 4.00;
	mat1[i][j] + 5.00;
	mat1[i][j] + 6.00;
  }
  
  }	
  c++;
}
//printf("c: %ld\n",c);
  pthread_exit(NULL);
}



void cpu_output_fun(char *filename,  char *cpu_precision,int thrdArray, double benchval,double th_val, double efficiency)
{
//char *op_file = replace(filename, ".dat",".out.dat");
char *cpu_output_filename ;

if(strcmp(filename,"cpu_DP_1thread.dat") == 0 )
{
	cpu_output_filename = "cpu_DP_1thread_out.dat";
}
else if (strcmp (filename,"cpu_DP_2thread.dat") == 0 )
{
	cpu_output_filename = "cpu_DP_2thread_out.dat";
}
else if (strcmp (filename,"cpu_DP_4thread.dat") == 0 )
{
	cpu_output_filename = "cpu_DP_4thread_out.dat";
}
else if (strcmp (filename,"cpu_HP_1thread.dat") == 0 )
{
	cpu_output_filename = "cpu_HP_1thread_out.dat";
}
else if (strcmp (filename,"cpu_HP_2thread.dat") == 0 )
{
	cpu_output_filename = "cpu_HP_2thread_out.dat";
}
else if (strcmp (filename,"cpu_HP_4thread.dat") == 0 )
{
	cpu_output_filename = "cpu_HP_4thread_out.dat";
}
else if (strcmp (filename,"cpu_SP_1thread.dat") == 0 )
{
	cpu_output_filename = "cpu_SP_1thread_out.dat";
}
else if (strcmp (filename,"cpu_SP_2thread.dat") == 0 )
{
	cpu_output_filename = "cpu_SP_2thread_out.dat";
}
else if (strcmp (filename,"cpu_SP_4thread.dat") == 0 )
{
	cpu_output_filename = "cpu_SP_4thread_out.dat";
}
else if (strcmp (filename,"cpu_QP_1thread.dat") == 0 )
{
	cpu_output_filename = "cpu_QP_1thread_out.dat";
}
else if (strcmp (filename,"cpu_QP_2thread.dat") == 0 )
{
	cpu_output_filename = "cpu_QP_2thread_out.dat";
}
else if (strcmp (filename,"cpu_QP_4thread.dat") == 0 )
{
	cpu_output_filename = "cpu_QP_4thread_out.dat";
}

char cpu_output_file_path[100] = "/exports/home/ppatel115/cs553-pa1/cpu/output/";
//char op_path[100] = "/home/ubuntu/cs553-pa1/cpu/output/";
char *s1=cpu_output_file_path;
char *s2=cpu_output_filename;
strcat(s1,s2);
FILE *cpu_output_filepointer = fopen (cpu_output_file_path , "w" );
fprintf(cpu_output_filepointer,"\nCPU BENCHMARK OUTPUT\n");
fprintf(cpu_output_filepointer, "Workload   Concurrency   MyCPUBenchValue   TheoreticalValue   MyCPUBenchEfficiency\n");
fprintf(cpu_output_filepointer,"%s \t  \t \t %d \t  \t  \t %f \t  \t \t %f \t \t  \t %f \n",cpu_precision,thrdArray,benchval,th_val,efficiency);
} 



int main(int argc, char **argv)
{
   char * line = NULL;
size_t len = 0;
ssize_t read;
struct timeval start, end;
char no_trd[2];
char prec[3];
char path[100] = "/exports/home/ppatel115/cs553-pa1/cpu/";
strcat(path,argv[1]);
//puts(path);
	  int j=1; 
	 FILE *cpufp = fopen (path , "r" );	          
	   while ((read = getline(&line, &len, cpufp)) != -1) 
	   {
		  // puts(line);
			if(j == 1)
			{
			   strcpy(prec,line);
			}
			else if(j == 2)
			{
				strcpy(no_trd,line);
			}
			j++ ;
	   }		  
  th_info info;
strcpy(info.cpu_prec,prec);
info.nt = atoi(no_trd);
     printf("Threads:%d \n",info.nt);
	printf("Prec  : %s",prec); 
	int no_thrdArray = atoi(no_trd);
	long idofthread;
	int create;
	strtok(prec,"\n");
	pthread_t thrdArray[no_thrdArray]; 
		   //printf("precision: %s\n",strtok(prec,"\n"));
		 // printf("thrdArray: %d\n",no_thrdArray);
gettimeofday(&start, NULL);          
for (idofthread = 0; idofthread < no_thrdArray; idofthread++) {
	//printf("%d\n",idofthread);
if(strcmp(prec,"QP") == 0 && no_thrdArray == 1)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, qp_1trd, (void *) NULL);
   
}   
else if(strcmp(prec,"QP") == 0 && no_thrdArray == 2)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, qp_2trd, (void *) NULL);
	
}
else if(strcmp(prec,"QP") == 0 && no_thrdArray == 4)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, qp_4trd, (void *) NULL);
	
} 



 else if(strcmp(prec,"SP") == 0 && no_thrdArray == 1)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, sp_1trd, (void *) NULL);
	
}
else if(strcmp(prec,"SP") == 0 && no_thrdArray == 2)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, sp_2trd, (void *) NULL);
	
}
else if(strcmp(prec,"SP") == 0 && no_thrdArray == 4)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, sp_4trd, (void *) NULL);
	
}


else if(strcmp(prec,"HP") == 0 && no_thrdArray == 1)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, hp_1trd, (void *) NULL);
	
}
else if(strcmp(prec,"HP") == 0 && no_thrdArray == 2)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, hp_2trd, (void *) NULL);
	
}
else if(strcmp(prec,"HP") == 0 && no_thrdArray == 4)
{
  // puts("here");
	create = pthread_create(&thrdArray[idofthread], NULL, hp_4trd, (void *) NULL);
	
}

else if(strcmp(prec,"DP") == 0 && no_thrdArray == 1)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, dp_1trd, (void *) NULL);
	
}
else if(strcmp(prec,"DP") == 0 && no_thrdArray == 2)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, dp_2trd, (void *) NULL);
	
} 
else if(strcmp(prec,"DP") == 0 && no_thrdArray == 4)
{
   
	create = pthread_create(&thrdArray[idofthread], NULL, dp_4trd, (void *) NULL);
	
}  

if (create) {
printf("Could not create thread %ld\n", idofthread);
}
}
for (idofthread = 0; idofthread < no_thrdArray; idofthread++) {
create = pthread_join(thrdArray[idofthread], NULL);
if (create) {
printf("Threads were not able to join %ld\n", idofthread);
}
}
  gettimeofday(&end, NULL);  
float cpu_time = (double) (end.tv_sec - start.tv_sec) + ((double) (end.tv_usec - start.tv_usec) / 1000000) ;

// 1 trillion / (cpu time * 1GB)
double cpu_final_value = 1000000000000.00 / ( cpu_time * 1000000000.00 ) ;
printf("Execution time :%f sec\n", cpu_time);
printf("GFLOPS : %f\n" , cpu_final_value ); 
float cpu_theo_value;
float cpu_eff;
if(strcmp(prec,"DP") == 0){
	float cpu_theo_value= 2*1*2.299*16 ;
	float cpu_eff = (cpu_final_value / cpu_theo_value) * 100;
	printf("TheoreticalValue : %f \n", cpu_theo_value);
	printf("CPU_Efficiency : %f \n", cpu_eff);	
	cpu_output_fun(argv[1],prec,info.nt,cpu_final_value,cpu_theo_value, cpu_eff);

	}

else if(strcmp(prec,"SP") == 0){
	float cpu_theo_value= 2*1*2.299*32 ;
	float cpu_eff = (cpu_final_value / cpu_theo_value) * 100;
	printf("TheoreticalValue : %f \n", cpu_theo_value);
	printf("CPU_Efficiency : %f \n", cpu_eff);
	cpu_output_fun(argv[1],prec,info.nt,cpu_final_value,cpu_theo_value, cpu_eff);
}

else if(strcmp(prec,"HP") == 0){
	float cpu_theo_value= 2*1*2.299*64 ;
	float cpu_eff = (cpu_final_value / cpu_theo_value) * 100;
	printf("TheoreticalValue : %f \n", cpu_theo_value);
	printf("CPU_Efficiency : %f \n", cpu_eff);
	cpu_output_fun(argv[1],prec,info.nt,cpu_final_value,cpu_theo_value, cpu_eff);
}

else if(strcmp(prec,"QP") == 0){
	float cpu_theo_value= 2*1*2.299*128 ;
	float cpu_eff = (cpu_final_value / cpu_theo_value) * 100;
	printf("TheoreticalValue : %f \n", cpu_theo_value);
	printf("CPU_Efficiency : %f \n", cpu_eff);
	cpu_output_fun(argv[1],prec,info.nt,cpu_final_value,cpu_theo_value, cpu_eff);
}


/* if(strcmp(prec,"QP") == 0)
{
long itr= 16666666667/no_thrdArray;
long i;
 gettimeofday(&start, NULL);
 while(i < itr)
 {
	 ++i;
 }
 gettimeofday(&end, NULL);
 double itertime = (float) (end.tv_usec - start.tv_usec) / 1000000 +
(float) (end.tv_sec - start.tv_sec);
double tot_time = tot_time - itertime;
printf("%elapsed: fs\n",tot_time);
} */

puts("CPU BENCHMARK ENDS\n\n");

}
