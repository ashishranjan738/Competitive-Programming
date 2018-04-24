#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s){
    string temp=s;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<s.length();i++){
        if (s[i]!=temp[i]){
            return false;
        }
    }
    return true;
}
string concat(string s,int index){
    string temp;
    for(int i=0;i<s.length();i++){
        if(index!=i){
            temp.push_back(s[i]);
        }
    }
    return temp;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(isPalindrome(s)){
            cout<<"-1\n";
            continue;
        }
    }
    return 0;
}
