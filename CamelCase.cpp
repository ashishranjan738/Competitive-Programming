#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    if(!s.length()){cout<<"0";return 0;}
    int count=1;
    for(int i=0;i<s.length();i++){
        if((int)s[i]>=65&&(int)s[i]<=90)count++;
    }
    cout<<count;
    return 0;
}
