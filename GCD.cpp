#include<bits/stdc++.h>
using namespace std;
int calGCD(int a,int b){
    if(a==0)
        return b;
    else
        return calGCD(b%a,a);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<calGCD(a,b);
    return 0;
}
