#include<bits/stdc++.h>
using namespace std;
int main(){
long double n,k,avg=0,sum=0;
cin>>n>>k;
int p=n;
avg=n-k+1;
long double arr[p];
for(int i=0;i<p;i++)
    cin>>arr[i];
if(p==1){
    sum+=arr[0]/avg;
}
else
for(int i=0;i<(p-1);i++)
   sum+=(arr[i]+arr[i+1]);

sum=sum/avg;

cout<<setprecision(10)<<fixed<<sum;
}
