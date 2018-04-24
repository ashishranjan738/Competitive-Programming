#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int a=0,b=1;
        long long int c;
        if(n==1){
            cout<<"1\n";
            continue;
        }
        else if(n==0){
            cout<<"0\n";
            continue;
        }
        for(int i=2;i<=n;i++){
            c=a%1000000007+b%1000000007;
            a=b;
            b=c;
        }
        cout<<c%1000000007<<endl;
    }

    return 0;
}
