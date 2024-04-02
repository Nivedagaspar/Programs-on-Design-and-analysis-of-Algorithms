#include<iostream>
using namespace std;
struct sub
{
	int low,high,sum;
};
sub maxcrossarray(int arr[],int n,int low,int mid,int high)
{
	int leftsum=-9999;
	int sum=0;
	int leftmax;
	sub s;
	for (int i=mid;i>=0;i--)
	{
		sum+=arr[i];
		if (sum>leftsum)
		{
			leftsum=sum;
			leftmax=i;
		}
    }
	int rightsum=-9999;
	sum=0;
	int rightmax;
	for (int i=mid+1;i<=high;i++)
	{
		sum+=arr[i];
		if (sum>rightsum)
		{
			rightsum=sum;
			rightmax=i;
		}
   }
   s.low=leftmax;
   s.high=rightmax;
   s.sum=leftsum+rightsum;
   return s;
}
sub maxsubarray(int arr[],int n,int low,int high)
{
	if (high==low)
	   {
	   	sub s;
	   	s.low=low;
	   	s.high=low;
	   	s.sum=arr[low];
	   	return s;
	   }
	else
	   {
	   	int mid=(low+high)/2;
	   	sub s1=maxsubarray(arr,n,low,mid);
	   	sub s2=maxsubarray(arr,n,mid+1,high);
	   	sub s3=maxcrossarray(arr,n,low,mid,high);	   
		if (s1.sum>=s2.sum && s1.sum>=s3.sum)	
		{
			return s1;
		}
		else if (s2.sum>=s1.sum && s2.sum>=s3.sum)	
		{
			return s2;
		}
		else
		{
			return s3;
		}
	   }
}
int main()
{
	int n=8;
	int arr[n];
	for (int i=0;i<n;i++)
	{
		cout<<"Enter:";
		cin>>arr[i];
	}
	sub s=maxsubarray(arr,n,0,n-1);
	cout<<"Sum:"<<s.sum<<" Low:"<<s.low<<" High:"<<s.high;
}
