#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
int count1=0;
for(int i=0;i<n&&k>0;i++){
    if(arr[i]<=8){
        k-=arr[i];
        count1++;
    }
    else if(i<n-1){
        k-=8;
        arr[i+1]+=arr[i]-8;
        count1++;
    }
    else{
        k-=8;
        count1++;
    }
}
k>0?cout<<"-1\n":cout<<count1<<endl;
return 0;}
