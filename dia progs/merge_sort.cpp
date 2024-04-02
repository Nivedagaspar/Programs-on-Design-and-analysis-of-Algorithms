#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
void merge(int *arr,int low,int mid,int high)
{
	int n1=mid-low+1;
	int n2=high-mid;
	int l[n1],r[n2];
	for (int i=0;i<n1;i++)
	{
		l[i]=*(arr+low+i);
	}
	for (int j=0;j<n2;j++)
	{
		r[j]=*(arr+mid+j+1);
	}
	int k=low,i=0,j=0;
	while(i<n1 && j<n2)
	{
		if (l[i]<=r[j])
		   {
		   	*(arr+k)=*(l+i);
		   	 k++;
		   	 i++;
		   }
		else
		   {
		   	*(arr+k)=*(r+j);
		   	 k++;
		   	 j++;
		   }
	}
	while (i<n1)
	{
		*(arr+k)=*(l+i);
		k++;
		i++;
	}
	while (j<n2)
	{
		*(arr+k)=*(r+j);
		k++;
		j++;
	}
}
void mergesort(int *arr,int low,int high)
{
	if (low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	int n=5,x;
	int arr[n];
	ofstream fout("mergenumbers.txt");
	for (int i=0;i<5;i++)
	{
		fout<<rand()%100;
		fout<<" ";
	}
	fout.close();
	ifstream fin("mergenumbers.txt");
	int i=0;
	while(fin>>x)
	{
		arr[i++]=x;
	}
	mergesort(arr,0,4);
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
