#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int fib[n+1]={0};
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=n;i++)
            fib[i]=fib[i-1]%1000000007+fib[i-2]%1000000007;
        cout<<fib[n]%1000000007<<endl;
    }
return 0;}
