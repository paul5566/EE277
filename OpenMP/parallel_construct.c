#include <stdio>
#include <stdlib>
#include <omp.h>

int main(){
    int thread_id;
    printf("I am the main thread.\n\n");

    #pragma omp parallel private(thread_id)
    {
        thread_id = omp_get_thread_num();

        printf("Thread %d: Hello.\n", thread_id);
        printf("Thread %d: Bye bye.\n", thread_id);
    }

    printf("\nI am the main thread.\n\n");
    return 0;
}
