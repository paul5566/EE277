#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
/*

***
	learn
	(1)thraed id:

				omp_get_thread_num();
				
	(2)Parallel Construct:
				
				#pragma omp parallel private(thread_id)
	
	(3)barrier Construct:

				#pragma omp barrier
***
	
	Reference:https://goo.gl/e1DDkd


*/

void Parallel_Construct(){
	int thread_id;
	printf("Barrier Construct\n"); 
	#pragma omp parallel private(thread_id)	
	{
        thread_id = omp_get_thread_num();

        printf("Thread %d: Excute.\n", thread_id);
        printf("Thread %d: Stop.\n", thread_id);
    }
}

void Barrier_Construct(){
	int thread_id;
	printf("Barrier Construct\n");
	#pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();

        printf("Thread %d: Excute.\n", thread_id);
        #pragma omp barrier
        printf("Thread %d: Stop.\n", thread_id);
    }
}

int main(void){
	Parallel_Construct();
	Barrier_Construct();
	return 0;
}
