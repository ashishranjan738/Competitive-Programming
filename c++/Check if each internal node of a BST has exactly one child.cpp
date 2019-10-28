#include<bits/stdc++.h>
using namespace std;
bool hasOnlyOneChild(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int nextdiff=arr[i]-arr[i+1];
        int lastdiff=arr[i]-arr[n-1];
        if(nextdiff*lastdiff<0){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<endl<<hasOnlyOneChild(arr,n);
return 0;}
