#include<bits/stdc++.h>
using namespace std;
int parent(int i){
    return (i-1)/2;
}
int lchild(int i){
    return 2*i+1;
}
int rchild(int i){
    return 2*i+2;
}
void swap(int *a,int *b){
    *a^=*b^=*a^=*b;
}
void printLevelOrder(int arr[],int n){
    int l=1;
    int temp=0;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        temp++;
        if(temp==l){
            cout<<endl;
            l<<=1;
            temp=0;
        }
    }
}
void constructHeap(int arr[],int n,int *heapsize,int key){
    if(*heapsize==n){
        cout<<"Over Flow\n";
        return;
    }
    if(*heapsize==0){
        arr[(*heapsize)++]=key;
        return;
    }
    else{
        arr[(*heapsize)++]=key;
        int i=(*heapsize)-1;
        while(i!=0 && arr[i]>arr[parent(i)]){
            swap(arr[i],arr[parent(i)]);
            i=parent(i);
        }
    }
    printLevelOrder(arr,*heapsize);
    cout<<endl<<endl;
}
void heapify(int arr[],int n,int i,int heapsize){
    int l=lchild(i);
    int r=rchild(i);
    int maximum=i;
    if(i<heapsize && arr[maximum]<arr[lchild]){
        maximum=l;
    }
    if(i<heapsize && arr[maximum]<arr[rchild]){
        maximum=r;
    }
    if(maximum!=i){
        swap(&arr[i],&arr[maximum]);
        heapify(arr,n,maximum,heapsize);
    }
}
int extractMax(int arr[],int n){
    if(heapsize==0)
        return INT_MIN;
    else if(heapsize==1)
        return arr[0];
    else{
        int temp=arr[0];
        swap(&arr[0],&arr[heapsize-1]);
        heapsize--;
        heapify(arr,n,0,heapsize);
        return arr[0];
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n],harr[n];
    int heapsize=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        constructHeap(harr,n,&heapsize,arr[i]);
    }
    printLevelOrder(harr,heapsize);
    cout<<endl ;
    return 0;
}
