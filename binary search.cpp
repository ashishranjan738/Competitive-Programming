#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int l,int r,int key){
    if(l<=r){
        int mid=l+(r-l)/2;
        if(arr[mid]==key)return mid;
        else if(key<arr[mid])return binarySearch(arr,l,mid-1,key);
        else return binarySearch(arr,mid+1,r,key);
    }
    else return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int key;
    cin>>key;
    cout<<"Index :"<<binarySearch(arr,0,n-1,key);
    return 0;
}
