#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,s1;
        cin>>s;
        for(int i=s.length()/2;i<s.length();i++){
            s1.push_back(s[i]);
        }
        if(s.length()&1){
            cout<<"-1 \n";
            continue;
        }
        int arr[26],arr1[26];
        memset(arr,0,sizeof(arr));
        memset(arr1,0,sizeof(arr));
        for(int i=0;i<s.length()/2;i++){
            arr[s[i]-97]++;
            arr1[s1[i]-97]++;
        }
        int sum=0;
        for(int i=0;i<26;i++){
            if(arr[i]<arr1[i]){
                sum+=arr1[i]-arr[i];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
