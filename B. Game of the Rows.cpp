#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,k;
cin>>n>>k;
long long int space=n*4;
int arr[k];
long long int count1=0;
for(int i=0;i<k;i++)
    cin>>arr[i];
for(int i=0;i<k;i++){
    count1+=arr[i]/2+arr[i]%2;
}
(count1<=space)?cout<<"YES\n":cout<<"NO\n";
return 0;}
