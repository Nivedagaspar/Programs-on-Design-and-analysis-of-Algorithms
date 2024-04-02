#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
using namespace std;
int getmax(int arr[],int n)
{
	int max=arr[0];
	for (int i=0;i<n;i++)
	{
		if (arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
int countingsort(int arr[],int n,int *op)
{
	int max=getmax(arr,n);
	int count[max+1];
	int output[n];
	for (int i=0;i<max+1;i++)
	{
		count[i]=0;
	}
	for (int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	for (int i=1;i<max+1;i++)
	{
		count[i]=count[i]+count[i-1];
	}
	for (int i=0;i<n;i++)
	{
		//*(op+count[arr[i]]-1)=arr[i];
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}
	for(int i = 0; i<n; i++) 
	{  
      arr[i] = output[i];  
    } 
}
int main()
{
	ofstream fout("Counting.txt");
	int n=5,x;
	int arr[n];
	int *op;
	clock_t start,end;
	double etime;
	for (int i=0;i<n;i++)
	{
		fout<<rand()%100<<" ";
	}
	fout.close();
	ifstream fin("Counting.txt");
	int i=0;
	while (fin>>x)
	{
		arr[i++]=x;
	}
	cout<<"\nArray before sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	start=clock();
	countingsort(arr,n,op);
	end=clock();
	etime=(double)(end-start)/CLOCKS_PER_SEC;
	cout<<"\nArray after sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nEtime:"<<etime;
}

