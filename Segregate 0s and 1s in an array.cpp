#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=n-1;
    while(l<r){
        while(arr[r]&&l<r)
            r--;
        while(!arr[l]&&l<r)
            l++;
        if(!arr[r]&&arr[l]&&l<r){
            arr[r]=1;
            arr[l]=0;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
