#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,s1;
        cin>>s>>s1;
        int arr[26]={0},arr1[26]={0};
        for(int i=0;i<s.length();i++)
            arr[s[i]-97]++;
        for(int i=0;i<s1.length();i++)
            arr1[s1[i]-97]++;
        bool flag=false;
        for(int i=0;i<26;i++){
            if(arr[i]&&arr1[i]){
                flag=true;
                break;
            }
        }
        flag?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}
