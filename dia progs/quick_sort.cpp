#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
int partition(int *arr,int low,int high)
{
	int pivot=arr[high];
	int i=low-1;
	for (int j=low;j<high;j++)
	{
		if (*(arr+j)<=pivot)
		{
			i++;
			swap(*(arr+j),*(arr+i));
		}
	}
	swap(*(arr+i+1),*(arr+high));
	return i+1;
}
void quicksort(int *arr,int low,int high)
{
	if (low<high)
	{
		int loc=partition(arr,low,high);
		quicksort(arr,low,loc-1);
		quicksort(arr,loc+1,high);
	}
}
int main()
{
	int n=5,x;
	int arr[n];
	ofstream fout("insertionsrtnumbers.txt");
	for (int i=0;i<5;i++)
	{
		fout<<rand()%100;
		fout<<" ";
	}
	fout.close();
	ifstream fin("insertionsrtnumbers.txt");
	int i=0;
	while(fin>>x)
	{
		arr[i++]=x;
	}
	quicksort(arr,0,n-1);
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
