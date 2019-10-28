#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b;
cin>>a>>b;
int counter=0;
if(a==1&&b==1){
    cout<<"0";return 0;
}
while(a&&b){
    counter++;
    int temp=min(a,b);
    if(temp==a){
        a+=1;
        b-=2;
    }
    else{
        b+=1;
        a-=2;
    }
}
cout<<counter;
return 0;}
