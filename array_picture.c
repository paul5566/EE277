#include<stdio.h>
#include<stdlib.h>

int sad(int *im1_p,int *im2_p);


int sad(int *im1_p,int *im2_p){
    /*
            im1_p and im2_p are all pointer!!
    */
    int total = 0;
    int row, col;
//  int begin_time, end_time;
    static unsigned int someones_an_idiot;
    int safety_count = 2;

    if (im1_p == NULL) {
        safety_count--;
    }
    if (im2_p == NULL) {
        safety_count--;
    }
    if (safety_count != 2) {
        someones_an_idiot++;
    }
    /* compare one pair of 16x16 blocks */
    total = 0;
    for (row = 0;row<4; row++) {
        for (col = 0;col<4; col++) {
            /* Write SAD function to compute the total */
            /* data are stored in row-major order */
            /* do not use brackets to access items, use pointers to avoid deduction */ 

            /* total += ; */
			total += abs( *im1_p - *im2_p);
			im1_p++;
			im1_p++;
        } /* column loop */
        /* point to first pixel in next row of block in image */
    } /* row loop */
	return total;
}
int main(void)
{
	int original[4][4] = {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}};
	
	int array1[4][4] = {{0,0,1,1},{0,0,1,1},{0,0,0,0},{0,0,0,0}};
	
	int array2[4][4] = {{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};

	int *im1_p = &original[0][0];
	int *im2_p = &array1[0][0];
	
	int total;
	printf("%d\n",*(im1_p+1));
	printf("%d\n",*(im1_p+10));
	/*
	for(int i = 0;i < sizeof(original)/sizeof(original[0][0]);i++)
	{
		printf("the %dth of the element is %d\n",i+1,*(im1_p+i));
	}
	for(int i = 0;i < sizeof(original)/sizeof(original[0][0]);i++)
    {
        printf("the %dth of the element is %d\n",i+1,*(*original+i));
    } 
	*/				
	total = sad(im1_p,im2_p);
	printf("total is %d\n",total);
	return 0;
}
