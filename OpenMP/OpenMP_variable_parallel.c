#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void Test(int n,int m)
{

	printf("<Thread %d> (%d,%d)\n",omp_get_thread_num(),n,m);
}
int main(void)
{
	printf("shared the memory\n");
	#pragma omp parallel for
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			Test(i,j);
		}
	}
	printf("shared the memory\n");
	int k,l;
	#pragma omp parallel for
	for(k=0;k<3;k++)
	{
		for(l=0;l<3;l++)
		{
			Test(k,l);
		}
	}
	printf("using private instruction in OpemMP\n");
	int m,n;
	#pragma omp parallel for private(n)
	for(m=0;m<3;m++)
    {
        for(n=0;n<3;n++)
        {
            Test(m,n);
        }
    }

	return 0;
}
