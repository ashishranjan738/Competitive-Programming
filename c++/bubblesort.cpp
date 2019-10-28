#include<bits/stdc++.h>
#include<time.h>
using namespace std;
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
bool isSorted(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            return 0;
    }
    return 1;
}
int main(){
int n;
cin>>n;
srand(time(0));
int arr[n];
for(int i=0;i<n;i++)
    arr[i]=rand()%n;
for(int i=0;i<n-1;i++){
    for(int j=i;j<n;j++){
        if(arr[i]>arr[j])
            swap(&arr[i],&arr[j]);
    }
}
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
isSorted(arr,n)?cout<<"\nSorted\n":cout<<"\nNot Sorted\n";
return 0;}

