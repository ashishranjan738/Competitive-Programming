#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3,s4;
    int arr1[26]={0},arr2[26]={0},arr3[26]={0},arr4[26]={0};
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<s1.length();i++)
        arr1[s1[i]-97]++;
    for(int i=0;i<s2.length();i++)
        arr2[s2[i]-97]++;
    for(int i=0;i<s3.length();i++)
        arr3[s3[i]-97]++;
    for(int i=0;i<s4.length();i++)
        arr4[s4[i]-97]++;
    bool flag1=0;
    bool flag2=0;
    for(int i=0;i<26;i++){
        if(arr1[i]&&arr4[i])
            flag1=true;
    }
    for(int i=0;i<26;i++){
        if(arr2[i]&&arr3[i])
            flag2=true;
    }
    int ans1=0;
    int ans2=0;
    if(flag1&&flag2){
        for(int i=0;i<26;i++){
            ans1+=arr2[i]*arr3[i];
            ans2+=arr1[i]*arr4[i];
        }
        cout<<ans1*ans2;
    }
    else cout<<"NOT POSSIBLE";
    return 0;
}
