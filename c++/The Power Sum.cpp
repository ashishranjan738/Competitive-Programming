#include<bits/stdc++.h>
using namespace std;
int count1=0;
void calWays(int x,int n,int sum,int i){
    if(i>x||sum+pow(i,n)>x)
        return;
    if((sum+pow(i,n))==x){
        count1++;
        return;
    }
    calWays(x,n,sum,i+1);
    calWays(x,n,sum+pow(i,n),i+1);
}
int main(){
    int x,n;
    cin>>x>>n;
    calWays(x,n,0,1);
    cout<<count1;
    return 0;
}
