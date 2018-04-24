#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
bool arr[26];
memset(arr,0,sizeof(arr));
getline(cin,s);
for(int i=0;i<s.length();i++){
    int temp=tolower(s[i])-'a';
    if(temp>=0&&temp<26){
        arr[temp]=true;
    }
}
bool flag=true;
for(int i=0;i<26;i++){
    if(!arr[i]){
        flag=false;break;
    }
}
flag?cout<<"pangram\n":cout<<"not pangram\n";
return 0;}
