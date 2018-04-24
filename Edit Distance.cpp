#include<bits/stdc++.h>
using namespace std;
int editDistances(const string &s1,const string &s2){
    if((!s1.length()&&!s2.length()))
        return 0;
    else if(!s1.length()&&s2.length())
        return s2.length();
    else if(s1.length()&&!s2.length())
        return s1.length();
    else if(s1[0]==s2[0]) return editDistances(s1.substr(1),s2.substr(1));
    else return min(editDistances(s1.substr(1),s2),min(editDistances(s1,s2.substr(1)),editDistances(s1.substr(1),s2.substr(1))))+1;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistances(s1,s2);
    return 0;
}
