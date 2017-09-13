/* EE296A Homework 1 template C code */

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
    }
	 printf("*im1_p is %d\n",*(im1_p+100));
    /* compare one pair of 16x16 blocks */
    total = 0;
    for (row = 0; row < 16; row++) {
        for (col = 0; col < 16; col++) {
	        /* Write SAD function to compute the total */
	        /* data are stored in row-major order */
			/* do not use brackets to access items, use pointers to avoid deduction */ 
	        
            /* total += ; */
			/*			
			point_of_value_imp1_p = *(im1_p+row*16+col);
			point_of_value_imp2_p = *(im2_p+row*16+col);
			different_value = abs(point_of_value_imp1_p - point_of_value_imp2_p);
			total = total + different_value;
			*/
			total += abs(*im1_p-*im2_p);
			im1_p++;
			im2_p++;
        } /* column loop */
        /* point to first pixel in next row of block in image */
		
    } /* row loop */


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
    printf("the total is %d\n",total);
	return(0);
} /* end of main */
