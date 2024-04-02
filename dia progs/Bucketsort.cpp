#include<iostream>
using namespace std;
struct Node
{
	double data;
	Node* link;
};
class Bucket
{
	private:
		Node* head;
		int size;
	public:
		Bucket()
		{
			head=NULL;
			size=0;
		}
		void insert(double x)
		{
			Node* pnew=new Node();
			pnew->data=x;
			pnew->link=head;
			head=pnew;
		}
		void sort()
		{
			Node *i,*j;
			double temp;
			for (i=head;i!=NULL;i=i->link)
			{
				for (j=i->link;j!=NULL;j=j->link)
				{
					if (j->data<i->data)
					{
						temp=j->data;
						j->data=i->data;
						i->data=temp;
					}
				}
			}
		}
		bool elementat(int loc,double &x)
		{
			int c=0;
			Node* ploc=head;
			while (ploc!=NULL)
			{
				if (c==loc)
				{
					x=ploc->data;
					return true;
				}
				ploc=ploc->link;
				c++;
			}
			return false;	
		}
		int getsize()
		{
			int c=0;
			Node* ploc=head;
			while(ploc!=NULL)
			{c++;
			 ploc=ploc->link;
			}
			return c;
		}
		void display()
		{
			Node* ploc=head;
			while(ploc!=NULL)
			{
			 cout<<ploc->data<<" ";
			 ploc=ploc->link;
			}
			cout<<"\n";
		}
};
void bucketsort(double arr[],int n)
{
	Bucket Buckets[n];
	double no;
	for (int i=0;i<n;i++)
	{
		int bno=arr[i]*n;
		Buckets[bno].insert(arr[i]);
	}
	cout<<"\nBucket before sorting:\n";
	for (int i=0;i<n;i++)
	{
		Buckets[i].display();
	}
	for (int i=0;i<n;i++)
	{
		Buckets[i].sort();
	}
	cout<<"\nBucket after sorting:\n";
	for (int i=0;i<n;i++)
	{
		Buckets[i].display();
	}
	for (int i=0,j=0;i<n;i++)
	{
		for (int p=0;p<Buckets[i].getsize();p++)
		{
			if (Buckets[i].elementat(p,no))
		    {
			    arr[j++]=no;
		    }
		}
	}
	cout<<"\nAfter sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cout<<"Enter num of elements:";
	cin>>n;
	double a[n];
	for (int i=0;i<n;i++)
	{
		cout<<"Enter:";
		cin>>a[i];
	}
	cout<<"Before sorting:\n";
	for (int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	bucketsort(a,n);
}
