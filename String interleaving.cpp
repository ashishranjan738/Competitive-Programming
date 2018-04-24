#include<bits/stdc++.h>
using namespace std;
bool isInterleaving(const string &s1,const string &s2,const string &s3){
    //cout<<endl<<s1<<endl<<s2<<endl<<s3<<endl;
    if(!s1.length()&&!s2.length()&&!s3.length()) return 1;
    else if(!s1.length()&&!s2.length()&&s3.length()) return 0;
    else if(s1.length()&&s2.length()&&!s3.length()) return 0;
    return ((s1.length()&&s3.length()&&(s1[0]==s3[0])?isInterleaving(s1.substr(1),s2,s3.substr(1)):0)||((s2.length()&&s3.length()&&(s2[0]==s3[0]))?isInterleaving(s1,s2.substr(1),s3.substr(1)):0));
}
int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<isInterleaving(s1,s2,s3);
    return 0;
}
