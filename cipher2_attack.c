#include<stdio.h>
unsigned int S_box(unsigned int i)
{
	unsigned int a[16]={0x6,0x4,0xc,0x5,0x0,0x7,0x2,0xe,0x1,0xf,0x3,0xd,0x8,0xa,0x9,0xb};
	return a[i];
}
unsigned int R_box(unsigned int x) //Inverse of the S is R
{
	unsigned int a[16]={0x4,0x8,0x6,0xa,0x1,0x3,0x0,0x5,0xc,0xe,0xd,0xf,0x2,0xb,0x7,0x9};
	return a[x]; 
}
unsigned int CIPHER_TWO(unsigned int m)
{
	unsigned int k0=0x7,k1=0xe,k2=0xa;
	unsigned int u,v,w,x,c;
	u=m^k0;
	v=S_box(u);
	w=v^k1;
	x=S_box(w);
	c=x^k2;
	return c;	
}
void main()
{
	unsigned int i,j,l;
	unsigned int m0,m1,c0,c1,x0[16],x1[16],w0[16],w1[16],v0[16],v1[16],z[16];
	unsigned int k2[16],T[16];
	for(i=0;i<16;i++)
	{
		k2[i]=i;
		T[i]=0;
	}
	printf("Number of iteration you want\n");
	scanf("%u",&l);
	unsigned int n0[l];
	for(i=0;i<l;i++)
	{
		printf("Enter the possible choice of m0 :\n");
		scanf("%u",&n0[i]);
	}
	
	for(i=0;i<l;i++)
	{
		m0=n0[i];	m1=m0^0xf;
		c0=CIPHER_TWO(m0);
		c1=CIPHER_TWO(m1);
		for(j=0;j<16;j++)
		{
			x0[j]=c0^k2[j];
			x1[j]=c1^k2[j];
			w0[j]=R_box(x0[j]);
			w1[j]=R_box(x1[j]);
			z[j]=w0[j]^w1[j];
			if(z[j]==0xd)
			{
				T[j]=T[j]+1;
			}
		}
	}
	for(i=0;i<16;i++)
	{
		printf("The value of the %u th counter is =%u\n",i,T[i]);
	}				
}
