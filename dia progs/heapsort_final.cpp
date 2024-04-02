#include<iostream>
#include<cstdlib>
#include<fstream>
#include<time.h>
using namespace std;
void heapify(int arr[],int i,int n)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if (left<n && arr[left]>arr[largest])
	    largest=left;
	if (right<n && arr[right]>arr[largest])
	    largest=right;
	if (largest!=i)
	   {
	   	swap(arr[largest],arr[i]);
	   	heapify(arr,largest,n);
	   }
}
void heapsort(int arr[],int n)
{
	for (int i=n/2-1;i>=0;i--)
	{
		heapify(arr,i,n);
	}
	cout<<"Array after build max heap:\n";
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	for (int i=4;i>=0;i--)
	{
		swap(arr[i],arr[0]);
		heapify(arr,0,i);
	}
}
int main()
{
	int n=5,x;
	int arr[n];
	clock_t start,end;
	ofstream fout("heapnumbers(2).txt");
	for (int i=0;i<5;i++)
	{
		fout<<rand()%100;
		fout<<" ";
	}
	fout.close();
	ifstream fin("heapnumbers(2).txt");
	int i=0;
	while(fin>>x)
	{
		arr[i++]=x;
	}
	start=clock();
	heapsort(arr,n);
	end=clock();
	double etime=(double)(end-start)/CLOCKS_PER_SEC;
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nExecution time:"<<etime;
	
}
