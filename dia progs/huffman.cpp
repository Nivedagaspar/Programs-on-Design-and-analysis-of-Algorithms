#include<iostream>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;
struct HTreeNode
{
	char symbol;
	int freq;
	string code;
	HTreeNode* left;
	HTreeNode* right;
};
HTreeNode* Heapextractmin(HTreeNode **Q,int &qsize)
{
	int min=99999;
	int minindex=-1;
	for (int i=0;i<qsize;i++)
	{
		if (Q[i]->freq < min)
		{
			min=Q[i]->freq;
			minindex=i;
		}
	}
	HTreeNode *temp;
	if (minindex!=-1)
	{
		temp=Q[minindex];
		Q[minindex]=Q[qsize-1];
		Q[qsize-1]=temp;
		qsize--;
	}
	else
	{
		cout<<"Invalid input"<<endl;
	}
	return temp;
}
void insertHeap(HTreeNode **Q,int &qsize,HTreeNode *newnode)
{
	Q[qsize]=newnode;
	qsize++;
}
HTreeNode* Hufftreebuild(HTreeNode *data,int n)
{
	HTreeNode **Q;
	int qsize=n;
	Q=new HTreeNode*[n];
	for (int i=0;i<n;i++)
	{
		Q[i]=&data[i];
	}
	HTreeNode *min1,*min2,*newnode,*htree;
	for (int i=0;i<n;i++)
	{
		min1=Heapextractmin(Q,qsize);
		min2=Heapextractmin(Q,qsize);
		newnode=new HTreeNode;
		newnode->left=min1;
		newnode->right=min2;
		newnode->freq=min1->freq+min2->freq;
		insertHeap(Q,qsize,newnode);
	}
	htree=Heapextractmin(Q,qsize);
	return htree;
}
void assigncode(HTreeNode* node ,string code)
{
	if (node->left==NULL && node->right==NULL)
	{
		node->code=code;
		code="";
	}
	if(node->left!=NULL)
	{
		assigncode(node->left,code+'1');
	}
	if(node->right!=NULL)
	{
		assigncode(node->right,code+'0');
	}
}
void generatehuffman(HTreeNode *data,int n)
{
	HTreeNode* htree;
	htree=Hufftreebuild(data,n);
	cout<<"Tree built"<<endl;
	string code="";
	assigncode(htree,code);
}
int main()
{
	int n;
	cout<<"Enter n:";
	cin>>n;
	cout<<"Got n";
	HTreeNode *data;
	cout<<"Htree made";
	data = new HTreeNode[n];
	for (int i=0;i<n;i++)
	{
		data[i].symbol=65+i;
		data[i].freq=(rand()%(n+50))+1;
		data[i].code="";
		data[i].left=NULL;
		data[i].right=NULL;
	}
	cout<<"Input to huffman"<<endl;
	cout<<"  Symbol  |"<<"  Frequency  "<<endl;
	for (int i=0;i<n;i++)
	    cout<<setw(10)<<data[i].symbol<<"|"<<setw(12)<<data[i].freq<<"|"<<endl;
	generatehuffman(data,n);
	cout<<"  Symbol  |"<<"  Frequency  |"<<"  Code  "<<endl;
	for (int i=0;i<n;i++)
	    cout<<setw(10)<<data[i].symbol<<"|"<<setw(12)<<data[i].freq<<"|"<<setw(8)<<data[i].code<<endl;
}
