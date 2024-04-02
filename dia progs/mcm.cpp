#include<iostream>
using namespace std;
int ind[4][4];
int mcm(int p[],int n)
{
	int mat[n][n];
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			ind[i][j]=-1;
		}
	}
	for (i=0;i<n;i++)
	{
		mat[i][i]=0;
	}
	for (int l=2;l<n;l++)
	{
		for (i=1;i<n-l+1;i++)
		{
			j=i+l-1;
			mat[i][j]=99999;
			for (k=i;k<j;k++)
			{
				int c=mat[i][k]+mat[k+1][j]+p[i-1]*p[k]*p[j];
				if (c<mat[i][j])
				{
					mat[i][j]=c;
					ind[i][j]=k;
				}
			}
		}
	}
	return mat[1][n-1];
}
void printparen(int i,int j)
{
	if (i==j)
	    cout<<"A"<<i;
	else
	{
		cout<<"(";
		printparen(i,ind[i][j]);
		printparen(ind[i][j]+1,j);
		cout<<")";
	}
}
int main()
{
	int p[]={40,20,30,10,30};
	int n=5;
	int cost=mcm(p,n);
	cout<<"Min Cost:"<<cost;
	printparen(1,n-1);
}
