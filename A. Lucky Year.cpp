#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,k,ld=0,length=-1;
cin>>n;
k=n;
while(n>0){
    ld=n%10;
    length++;
    n/=10;
}
//if(ld==9)
  //  length--;
//else
ld++;
for(int i=0;i<length;i++)
    ld*=10;
cout<<ld-k;
//cout<<p<<endl;
//cout<<p-k<<endl;
//cout<<200-100;
return 0;}
