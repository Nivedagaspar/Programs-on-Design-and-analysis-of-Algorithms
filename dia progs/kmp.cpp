#include<iostream>
#include<cstring>
using namespace std;
void computelps(char patt[],int m,int *lps);
void kmp(char text[],char patt[])
{
	int n=strlen(text);
	int m=strlen(patt);
	int lps[m];//longest prefix suffix
	computelps(patt,m,lps);
	cout<<"LPS: ";
	for (int i=0;i<m;i++)
	{
		cout<<lps[i]<<" ";
	}
	int i=0;
	int j=0;
	while((n-i)>=(m-j))
	{
		if (text[i]==patt[j])
		{
			i++;
			j++;
		}
		if (j==m)
		{
			cout<<"Pattern found at index "<<i-m;
			j=lps[j-1];
		}
		else if (i<n && text[i]!=patt[j])
		{
			if (j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i=i+1;
			}
		}
	}
}
void computelps(char patt[],int m,int *lps)
{
	int len=0;
	int i=1;
	lps[0]=0;
	while (i<m)
	{
		if (patt[i]==patt[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if (len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
	cout<<"LPS(inside compute): ";
	for (int i=0;i<m;i++)
	{
		cout<<lps[i]<<" ";
	}
}
int main()
{
	char text[100],patt[100];
	cout<<"Enter text:";
	cin>>text;
	cout<<"Enter pattern:";
	cin>>patt;
	kmp(text,patt);
}
