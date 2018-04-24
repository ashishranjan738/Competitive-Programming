#include<bits/stdc++.h>
using namespace std;
void swapelement(int *a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void segregate(int arr[],int n){
    int l=0,r=n-1;
    while(l<r){
        while(arr[l]%2==0&&l<r)
            l++;
        while(arr[r]%2!=0&&l<r)
            r--;
        if(l<r){
            swapelement(&arr[l],&arr[r]);
            l++;
            r--;
        }
    }
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    segregate(arr,n);
    int boundary=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            sort(arr,arr+i);
            boundary=i;
            break;
        }
    }
    sort(arr+boundary,arr+n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
return 0;}
