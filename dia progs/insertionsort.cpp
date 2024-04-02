#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
void insertionsrt(int arr[],int n)
{
	for (int j=1;j<n;j++)
	{
		int key=arr[j];
		int i=j-1;
		while (i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
	for (int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
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
	insertionsrt(arr,5);
}
