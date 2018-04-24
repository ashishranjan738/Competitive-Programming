#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;
cin>>n>>k;
double a[n],sum=0;
int i;
for(i=0;i<n;i++){
    cin>>a[i];sum+=a[i];}
if(round(sum/n)==k){
    cout<<'0';
    return 0;
}
int l=0;
while(round(sum/(n+l))!=k){
    l++;
    sum+=k;
}
cout<<l;
return 0;}
