#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int absdiff=INT_MAX;
    for(int i=0;i<n-1;i++){
        if(abs(arr[i]-arr[i+1])<absdiff){
            absdiff=abs(arr[i]-arr[i+1]);
        }
    }
    cout<<absdiff<<endl;
    return 0;
}
