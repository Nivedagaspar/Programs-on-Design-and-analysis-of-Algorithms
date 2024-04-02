#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
void insertionsrt(int arr[],int n)
{   int key,i;
	for (int j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		while (i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i=i-1;
		}
		arr[i+1]=key;
	}
	for (i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	ifstream fin;
	ofstream fout;
	int x,i=0,arr[10],N=10;
	fout.open("numbers3.txt");
	for (int j=0;j<N;j++)
	{
		fout<<rand()%100<<endl;
	}
	fout.close();
	fin.open("numbers3.txt");
	while(1)
	{
		fin>>x;
		if (fin.eof())
		    break;
		arr[i++]=x;
	}
	cout<<"Before sorting:\n";
	for (int j=0;j<N;j++)
	{
		cout<<arr[j]<<" ";
	}
	cout<<"\nAfter sorting:\n";
	insertionsrt(arr,N);
}
