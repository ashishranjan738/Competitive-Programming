#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,s1;
    cin>>s>>s1;
    int arr[26]={0},arr1[26]={0};
    for(int i=0;i<s.length();i++)
        arr[s[i]-97]++;
    for(int i=0;i<s1.length();i++)
        arr1[s1[i]-97]++;
    int sum=0;
    for(int i=0;i<26;i++){
        sum+=abs(arr[i]-arr1[i]);
    }
    cout<<sum<<endl;
    return 0;
}
