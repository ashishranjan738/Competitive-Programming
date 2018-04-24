#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt=0;
        bool arr[26]={0};
        for(int i=0;i<s.length();i++)
            arr[s[i]-'a']=true;
        for(int i=0;i<26;i++){
            if(arr[i])cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
