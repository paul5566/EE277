/* EE296A Homework 1 template C code */
/*
No:012485564
Name:Polin Chen
*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 144
#define COLS 176

static unsigned char image1[ROWS][COLS] __attribute__ ((aligned (16)));
static unsigned char image2[ROWS][COLS] __attribute__ ((aligned (16)));

int sad(const unsigned char *im1_p, const unsigned char *im2_p,
        int numcols);


int sad(const unsigned char *im1_p, const unsigned char *im2_p,
              int numcols) {
	/*
			im1_p and im2_p are all pointer!!
	*/
    int total;
    int row, col;
	int count = 0;
//    int begin_time, end_time;
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
	return -1;//to check the code is working or not
    }
    /* compare one pair of 16x16 blocks */
    total = 0;
    for (row = 0; row < 16; row++) {
        for (col = 0; col < 16; col++) {
	        /* Write SAD function to compute the total */
	        /* data are stored in row-major order */
			/* do not use brackets to access items, use pointers to avoid deduction */ 
			total += abs(*im1_p-*im2_p);
			im1_p++;
			im2_p++;
			count++;
        } /* column loop */
        /* point to first pixel in next row of block in image */
		im1_p = im1_p + (COLS - 16);//bcz the pixel in the memory of array is not continuous  
		im2_p = im2_p + (COLS - 16);
    } /* row loop */
	printf("count is %d\n",count);
    return(total);
} 


int main(int argc, char *argv[]) {

    unsigned int total;
    unsigned char *im1_p, *im2_p;
    int row, col;
    int block_row, block_col;

    /* initialize source data  */
    for (row = 0; row < ROWS; row++) {
        im1_p = image1[row]; /* point to first pixel in row */
        im2_p = image2[row];
        for (col = 0; col < COLS; col++) {
            unsigned char temp;
                
            temp = ((row+col+120) % 256); /* sort of a random number */
            *im1_p++ = temp;
			*im2_p++ = 255-temp;
        } /* column loop */
    } /* row loop */

    block_row = 0;
    block_col = 0;

    /* point to first pixel in each block */
    im1_p = &image1[16*block_row][16*block_col];
    im2_p = &image2[16*block_row][16*block_col];

    total = sad(im1_p, im2_p, COLS);   
	if (total == -1)
	{
		printf("there are some problem in the picture of reference");
	} 
    printf("the total is %d\n",total);
	return(0);
} /* end of main */
