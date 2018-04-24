#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++){
        int j=i;
        while(j<n&&arr[j]<arr[i]+k){
            j++;
        }
        i=j;
        sum++;
       // cout<<"After sum"<<i<<endl;
        j=i;
        while(j<n&&arr[j]<=arr[i]+k){
            j++;
        }
        i=j;
        //cout<<"Before end"<<i<<endl;
    }
    cout<<sum;
    return 0;
}
