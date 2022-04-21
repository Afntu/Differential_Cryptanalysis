#include<stdio.h>
unsigned char S_box(unsigned char x)
{	
	unsigned int a[16]={0x6,0x4,0xc,0x5,0x0,0x7,0x2,0xe,0x1,0xf,0x3,0xd,0x8,0xa,0x9,0xb}
	return a[x];
}
unsigned char R_box(unsigned char x) //Inverse of the S is R
{
	unsigned int a[16]={0x4,0x8,0x6,0xa,0x1,0x3,0x0,0x5,0xc,0xe,0xd,0xf,0x2,0xb,0x7,0x9}
	return a[x];
}
unsigned char CIPHER_TWO(unsigned char m)
{
	unsigned char k0=0x7,k1=0xe,k2=0x2;
	unsigned char u,v,w,x,c;
	u=m^k0;
	v=S_box(u);
	w=v^k1;
	x=S_box(w);
	c=x^k2;
	return c;	
}
void main()
{
	unsigned char i,j,max=0;
	unsigned char m0,m1,n0[6],n1[6],c0,c1,x0[16],x1[16],w0[16],w1[16],v0[16],v1[16],z[16];
	unsigned k2[16],T[16];
	for(i=0;i<16;i++)
	{
		k2[i]=i;
		T[i]=0;
	}
	for(i=0;i<6;i++)
	{
		printf("Enter the possible choice of m0:\n");
		scanf("%u",&n0[i]);
	}
	for(i=0;i<6;i++)
	{
		printf("Enter the possible choice of m1:\n");
		scanf("%u",&n1[i]);
	}
	for(i=0;i<6;i++)
	{
		m0=n0[i];	m1=n1[i];
		c0=CIPHER_TWO(m0);
		c1=CIPHER_TWO(m1);
		for(j=0;j<16;j++)
		{
			x0[j]=c0^k2[j];
			x1[j]=c1^k2[j];
			w0[j]=R_box(x0[j]);
			w1[j]=R_box(x1[j]);
			z[j]=w0[j]^w1[j];
			if(z[j]==13)
			{
				T[j]=T[j]+1;
			}
		}
	}
	for(i=0;i<16;i++)
	{
		printf("%u\n",T[i]);
	}				
	/*for(j=0;j<16;j++)
	{
		for(i=0;i<16;i++)
		{
			if(T[j]>=T[i])
				max=max+1;
		}
		if(max==16)
			printf("final key index is %0x\n",j);		
	}*/	
}
