#include <stdio>
#include <stdlib>
#include <omp.h>

int main(void){
    int a[12];
    int i, tid, nthreads;

    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num();

        #pragma omp for 
        for(i=0; i<12; i++){
            a[i] = i;
            printf("Thread %d: a[%d] = %d\n", tid, i, a[i]);
        }
    }

    return 0;
}
