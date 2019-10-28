#include<bits/stdc++.h>
using namespace std;
int count(int arr[],int n,int m){
    if(m==0)
        return 1;
    if(m<0)
        return 0;
    if(n<=0&&m>=1)
        return 0;
    else return count(arr,n-1,m)+count(arr,n,m-arr[n]);
}
int main(){
int n;
cin>>n;
int arr[n];
int m;
cin>>m;
for(int i=0;i<n;i++)
    cin>>arr[i];
cout<<endl<<count(arr,n-1,m);
return 0;}
