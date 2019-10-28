#include<bits/stdc++.h>
using namespace std;
int numDecodings(string s){
    int count=0;
    if(s.length()==0)
        return 1;
    if(stoi(s.substr(0,1))==0)
        return 0;
    if(stoi(s.substr(0,1))!=0)
        count+=numDecodings(s.substr(1));
    if(s.length()>=2 && stoi(s.substr(0,2))<=26 && stoi(s.substr(0,2))>=1)
        count+=numDecodings(s.substr(2));
    return count;
}
int numDecodingsDP(string s){
    s.erase(0, min(s.find_first_not_of('0'), s.length()-1));
    vector<int> v(s.length()+1,0);
    v[0]=1;
    v[1]=1;
    for(int i=2;i<s.length()+1;i++){
        if(stoi(string(1,s[i-1]))>0)
            v[i]=v[i-1];
        if(s[i-2]!='0' && stoi(s.substr(i-2,2))>0 && stoi(s.substr(i-2,2))<=26)
            v[i]+=v[i-2];
    }
    return v[s.length()];
}
int numDecodingsR(string s,int i){
    if(i==0)
        return 1;
    else if(i==1 && s[i-1]=='0')
        return 0;
    else if(i==1)
        return 1;
    int count=0;
    if(stoi(string(1,s[i-1]))>0)
        count=numDecodingsR(s,i-1);
    if(i>=2 && s[i-2]!='0' && stoi(s.substr(i-2,2))>0 && stoi(s.substr(i-2,2))<=26)
        count+=numDecodingsR(s,i-2);
    return count;
}
int numDecodingsRDP(string s){
    vector<int> v(s.length()+1);
    v[0]=v[1]=1;
    for(int i=s.length())
}
int main(){
    string s;
    cin>>s;
    cout<<numDecodingsR(s,s.length());
    return 0;
}