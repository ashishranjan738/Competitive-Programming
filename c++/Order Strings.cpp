#include<bits/stdc++.h>
#include<string>
using namespace std;
int key;
bool rever,lexo;
vector<string> split(const string& str, const string& delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do{
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
bool comp(vector<string> a,vector<string> b){
    //if(key>a.size()||key>b.size())
        //return 1;
    int tem=key;
    //while(tem<a.size() && tem<b.size() && a[tem-1]==b[tem-1])
        //tem++;
    int key1=tem;//=min((int)a.size(),tem);
    int key2=tem;//min((int)b.size(),tem);
    if(lexo)
         return a[key1-1]<=b[key2-1];
    string x,y;
    int i;
    for(i=0;i<a[key1-1].size()-1&& a[key1-1][i]=='0';i++);
    x=a[key1-1].substr(i);
    for(i=0;i<b[key2-1].size()-1&&b[key2-1][i]=='0';i++);
    y=b[key2-1].substr(i);
    //cout<<x<<" "<<y<<endl;
    if(x.length()==y.length()){
        return x<y;
    }
    return  x.length()<y.length();
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        v[i]=split(temp," ");
    }
    cin>>key;
    string cond,type;
    cin>>cond>>type;
    cond=="false"?rever=0:rever=true;
    type=="lexicographic"?lexo=1:lexo=0;
    sort(v.begin(),v.end(),comp);


    return 0;
}
