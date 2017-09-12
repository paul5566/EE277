#include<stdio.h>                                                                                                                                                      
#include<stdlib.h>
#include<omp.h>
/*

Reference:
 * https://goo.gl/X3omgr

 using the forloop to display the thread mechanism in the function

 */


void test(int n){
	printf("the i is %d\n",n);
}

int main(void){

	printf("normal forloop\n");

	for(int i=0;i<10;i++){
		test(i);
	}

	printf("using the OpenMP in the forloop\n");

#pragma omp parallel for

	for(int i=0;i<10;i++){
		test(i);
	}

	return 0;
}

