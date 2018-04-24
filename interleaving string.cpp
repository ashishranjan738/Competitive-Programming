#include<bits/stdc++.h>
using namespace std;
bool isInterleaved(const string &s1,const string &s2,const string &s3){
    if(!s3.length()&&!s2.length()&&!s1.length())
        return true;
    if(!s3.length())
        return false;
    if(!s2.length()&&!s1.length())
        return false;
    if(s3[0]==s1[0]){
        return isInterleaved(s1.substr(1),s2,s3.substr(1));
    }
    else if(s3[0]==s2[0])
        return isInterleaved(s1,s2.substr(1),s3.substr(1));
}
int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<isInterleaved(s1,s2,s3);
return 0;}
