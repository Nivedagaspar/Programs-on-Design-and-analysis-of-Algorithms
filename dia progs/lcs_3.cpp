#include<iostream>
using namespace std;
class lcs{
private:
int c[6][7];
string b[10][10];
public:
lcs(){
for(int i=0;i<6;i++){
for(int j=0;j<7;j++){
c[i][j] = 0;
}
}
}
void lcs_length(string x,string y){
int m = x.length();
int n = y.length();

for(int i =1;i<=m;i++){
for(int j=1;j<=n;j++){
if(x[i] == y[j]){
c[i][j] = c[i-1][j-1]+1;
b[i][j] = "across";
}
else if(c[i-1][j]>=c[i][j-1]){
c[i][j] = c[i-1][j];
b[i][j] = "up";
}
else {
c[i][j] = c[i][j-1];
b[i][j] = "left";
}
}}
}
void print_lcs(string x,string y){
int m = x.length();
int n = y.length();
for(int i=0;i<=m;i++){
for(int j=0;j<=n;j++){
cout<<c[i][j]<<"\t";
}
cout<<endl;
}
for(int i=0;i<=m;i++){
for(int j=0;j<=n;j++){
cout<<b[i][j]<<"\t";
}
cout<<endl;
}
}

};
int main(){
lcs l;
string x ="abcbdab",y="abdcaba";
l.lcs_length(x,y);
l.print_lcs(x,y);
}
