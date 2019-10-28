#include<bits/stdc++.h>
using namespace std;
int m[5001];
int solve(const string &s){
    //cout<<"String :"<<s<<endl;
    if(s.length()==0)
        return 1;
    if(m[s.length()]!=0 && s.length()){
        return m[s.length()];
    }
    int temp1=0,temp2=0;
    if(s.length()>=2 && stoi(s.substr(0,2))<=26 && stoi(s.substr(0,2))>=1 && s[0]!='0')temp1=solve(s.substr(2));
    if(s.length() && s[0]!='0')temp2=solve(s.substr(1));
    return m[s.length()]=temp1+temp2;
}
int main(){
    string s;
    memset(m,0,sizeof(m));
    while(cin>>s){
        if(s.compare("0")==0)
            return 0;
        cout<<solve(s)<<endl;
        memset(m,0,sizeof(m));
    }
    return 0;
}
