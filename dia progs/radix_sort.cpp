#include<iostream>
#include<time.h>
#include<cstdlib>
#include<math.h>
using namespace std;
int getmax(int arr[],int n)
{
	int max=arr[0];
	for (int i=1;i<n;i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
int getdigit(int num,int d)
{
	int tmp=num/pow(10,d-1);
	return tmp%10;
}
void countingsort(int *arr,int n,int max,int d)
{
	int count[max+1];
	int op[n];
	int s=getdigit(*(arr+i),d);
	for (int i=0;i<max+1;i++)
	{
		count[i]=0;
	}
	for (int i=0;i<n;i++)
	{
		count[s]++;
	}
	for (int i=1;i<max+1;i++)
	{
		count[i]+=count[i-1];
	}
	for (int i=0;i<n;i++)
	{
		op[count[s]-1]=*(arr+i);
		count[s]--;
	}
	for (int i=0;i<n;i++)
	{
		*(arr+i)=op[i];
	}
}
void radixsort(int arr[],int n,int nd)
{
	for(int d=1;d<=nd;d++)
	{
		countingsort(arr,n,9,d);
	}
}
int main()
{
	int n=5;
	int nd;
	cout<<"Enter max d:";
	cin>>nd;
	int arr[n];
	int range=pow(10,nd)-1;
	for (int i=0;i<n;i++)
	{
		arr[i]=rand()%range;
	}
	cout<<"\nArray before sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	radixsort(arr,n,nd);
	cout<<"\nArray after sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
