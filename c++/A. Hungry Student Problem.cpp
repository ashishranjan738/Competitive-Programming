#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        if((n%7)%3==0||(n%3)%7==0)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}