#include<bits/stdc++.h>
using namespace std;
void swapint(int *i,int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++)
        if(arr[i]>arr[i+i])swapint(&arr[i]),&arr[i+1]);
    bubblesort(arr,n-1);
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
return 0;}
