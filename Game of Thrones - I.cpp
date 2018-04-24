#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int arr[26];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<s.length();i++){
        arr[s[i]-97]++;
    }
    for(int i=0;i<26;i++){
        arr[i]%=2;
    }
    int sum=0;
    for(int i=0;i<26;i++){
        if(arr[i]==1){
            sum++;
        }
        if(sum>1){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
