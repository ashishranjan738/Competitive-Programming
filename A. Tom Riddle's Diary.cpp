#include<bits/stdc++.h>
using namespace std;
int main(){
    map<string,bool> m;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        m[s]?cout<<"YES\n":cout<<"NO\n";
        m[s]=1;
    }
    return 0;
}
