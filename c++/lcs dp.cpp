#include<bits/stdc++.h>
using namespace std;
int lcsdp(const string &s1,const string &s2){
    vector<vector<int>> v(s1.length()+1,vector<int> (s2.length()+1));
    for(int i=0;i<s1.length()+1;i++){
        for(int j=0;j<s2.length()+1;j++){
            if(i==0||j==0)
                v[i][j]=0;
            else{
                if(s1[i-1]==s2[j-1])
                    v[i][j]=v[i-1][j-1]+1;
                else v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    return v[s1.length()][s2.length()];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcsdp(s1,s2);
    return 0;
}
