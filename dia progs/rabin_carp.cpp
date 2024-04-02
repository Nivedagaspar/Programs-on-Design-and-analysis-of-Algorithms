#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
void rabin_carp(char text[],char patt[],int d,int q)
{
	int n=strlen(text);
	int m=strlen(patt);
	long int h=long(pow(d,m-1))%q;
	long int p=0,t=0;
	for (int i=0;i<m;i++)
	{
		p=(p*d+patt[i]-'a'+1)%q;
		t=(t*d+text[i]-'a'+1)%q;
	}
	cout<<"Hashcode of pattern:"<<p<<endl;
	for (int s=0;s<=n-m;s++)
	{
		cout<<"T"<<s<<"="<<t<<endl;
		if (p==t)
		{
			int flag=1;
			for (int i=0;i<m;i++)
			{
				if (text[s+i]!=patt[i])
				{
					flag=0;
					break;
				}
			}
			if (flag)
			   cout<<"Found pattern at shift "<<s<<endl;
		}
		if (s<n-m)
		   t=(((t-(text[s]-'a'+1)*h)*d)+(text[s+m]-'a'+1))%q;
	}
}
int main()
{
	char text[100],patt[100];
	cout<<"Enter text:";
	cin>>text;
	cout<<"Enter pattern:";
	cin>>patt;
	rabin_carp(text,patt,10,10000);
}
