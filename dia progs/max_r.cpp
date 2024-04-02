#include<iostream>
using namespace std;
struct sub
{
int low,high,sum;
};
sub crossingarray(int a[],int low,int mid,int high)
{
int leftsum=-9999;
int sum=0;
int leftindex;
for(int i=mid;i>=0;i--)
{
sum=sum+a[i];
if(sum>leftsum)
{
leftsum=sum;
leftindex=i;
}
}
int rightsum=-9999;
sum=0;
int rightindex;
for(int i=mid+1;i<=high;i++)
{
sum=sum+a[i];
if(sum>rightsum)
{
leftsum=sum;
rightindex=i;
}
}
sub s;
s.low=leftindex;
s.high=rightindex;
s.sum=leftsum+rightsum;
return s;
}
sub maxsubarray(int a[],int low,int high)
{
if(low==high)
{
sub s;
s.low=low;
s.high=high;
s.sum=a[low];
return s;
}
else
{
int mid=(low+high)/2;
sub s1=maxsubarray(a,low,mid);
sub s2=maxsubarray(a,mid+1,high);
sub s3=crossingarray(a,low,mid,high);
if(s1.sum>=s2.sum && s1.sum>=s3.sum)
{
return s1;
}
else if(s2.sum>=s1.sum && s2.sum>=s3.sum)
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
int n;
cout<<"Enter number of elements: ";
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
sub s=maxsubarray(a,0,n-1);
cout<<"index "<<s.low<<" to "<<s.high<<" sum: "<<s.sum;
return 0;
}
