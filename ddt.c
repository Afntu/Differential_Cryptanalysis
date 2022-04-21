#include<stdio.h>
int S_box(int i)
{
	int a[16]={0x6,0x4,0xc,0x5,0x0,0x7,0x2,0xe,0x1,0xf,0x3,0xd,0x8,0xa,0x9,0xb};
	return a[i];
}
int main()
{
	int i,j,matrix[16][16],input_xor,output_xor;
	// initialize the matrix
	for (i = 0; i < 16; i++)
       {
        	for (j = 0; j < 16; j++)
        	{
                	matrix[i][j]=0;
        	}
       }
       for (i = 0; i < 16; i++)
       {
        	for (j = 0; j < 16; j++)
        	{
                	input_xor=i^j;
                	output_xor=S_box(i)^S_box(j);
                	matrix[input_xor][output_xor]++;
        	}
       }
       // Display the matrix  
       for (i = 0; i < 16; i++)
       {
        	for (j = 0; j < 16; j++)
        	{
                	printf("%d\t",matrix[i][j]);
        	}
        	printf("\n");
       }	
}
