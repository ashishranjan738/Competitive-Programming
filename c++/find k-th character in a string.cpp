#include<bits/stdc++.h>
using namespace std;
string toBinary(int n){
    string r;
    while(n!=0){
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}
void modify(string &s){
    string temp=s;
    s.clear();
    for(int i=0;i<temp.length();i++){
        if(temp[i]=='0'){
            s.push_back('0');
            s.push_back('1');
        }
        else{
            s.push_back('1');
            s.push_back('0');
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n,k;
        cin>>m>>k>>n;
        string s=toBinary(m);
        cout<<s<<endl;
        while(n--)
            modify(s);
        //cout<<s;
        cout<<s[k]<<endl;
    }
    return 0;
}
