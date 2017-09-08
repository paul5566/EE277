#include<stdio.h>
#include<stdlib.h>

int main(void){

	int array[5]={1,2,3,4,5};
	int maze[2][3] = {{1, 2, 3},{4, 5, 6}};
	int arr[3][3];
	//printf("the value of 5th element is %d\n",*(array+4));
	//printf("the maze of(2,3) is %d\n",*(array+4));
	//printf("the adress of (2,3) is %p\n",array+5);
	int sum = 0;
	int element;
	int i;
	int j;
	for(i=0;i<3;i++){
		
		for(j=0;j<3;j++)
		{
			sum += 1; 
			*((*arr+i)+j) = sum;	//*arr+i代表
		}
	}
	printf("the first element's address of the array is %p\n",arr);
	printf("the first element's value of the array is %d\n",**arr);
	printf("the second element's address of the array is %p\n",arr+1);
	printf("the third element of the array is %p\n",arr+2);
	printf("the 4th element of the array is %p\n",arr+3);
	printf("the 4th elment of the array is %p\n",(arr+1*2)+1);
	printf("the 4th element of the array is %d\n",*(*arr+1*2+1));	
	return 0;
}
