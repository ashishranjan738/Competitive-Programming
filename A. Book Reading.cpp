#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long int t;
    cin>>n>>t;
    long long int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int sol=0;
    for(int i=0;i<n && t>0;i++){
        t-=86400-arr[i];
        sol++;
    }
    cout<<sol<<endl;
    return 0;
}
