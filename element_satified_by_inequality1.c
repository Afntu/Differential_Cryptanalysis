//It checks a given point stisfied by some inequalities or not? 

#include<stdio.h>
#include<stdlib.h>
int checking(int **x,int **y,int **a,int *p,int i)
{
	a[i][0] = x[i][0] + x[i][1] - x[i][2] + y[i][2];
	a[i][1] = x[i][0] - x[i][1] + x[i][2] + y[i][1];
	a[i][2] = - x[i][0] + x[i][1] + x[i][2] + y[i][0];
	a[i][3] = y[i][0] + y[i][1] - y[i][2] + x[i][2];
	a[i][4] = y[i][0] - y[i][1] + y[i][2] + x[i][1];
	a[i][5] = - y[i][0] + y[i][1] + y[i][2] + x[i][0];
	if((a[i][0] >= 0) && (a[i][1] >= 0) && (a[i][2] >= 0) && (a[i][3] >= 0) && (a[i][4] >= 0) && (a[i][5] >= 0))
		p[i] = 1;
	else
		p[i] = 0;
	return p[i];		
}
int main()
{
	int **x,**y,**a,n;
	printf("Enter how many points you want to checks\n");
	scanf("%d",&n);
	int p[n];
	x = (int**)malloc(n*sizeof(int*));
	y = (int**)malloc(n*sizeof(int*));
	a = (int**)malloc(n*sizeof(int*));
	for(int i1=0; i1<3; i1++)
	{
		x[i1] = (int*)malloc(3*sizeof(int));
		y[i1] = (int*)malloc(3*sizeof(int));
	}
	for(int i1=0; i1<6; i1++)
	{
		a[i1] = (int*)malloc(6*sizeof(int));
	}
	printf("Enter the points to check either it satisfied by the inequalities or not? \n");
	for(int i = 0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d",&x[i][0],&x[i][1],&x[i][2],&y[i][0],&y[i][1],&y[i][2]);
		checking(x,y,a,&p[i],i);
	} 
	for(int i = 0;i<n;i++)
	{
		if(p[i] == 1)
			printf("The given point (%d,%d,%d,%d,%d,%d) is satisfied by the inequalities\n",x[i][0],x[i][1],x[i][2],y[i][0],y[i][1],y[i][2]);	
		if(p[i] == 0)
			printf("The given point (%d,%d,%d,%d,%d,%d) is not satisfied by the inequalities\n",x[i][0],x[i][1],x[i][2],y[i][0],y[i][1],y[i][2]);		
		
	} 	
	return 0;	
	
		
}
