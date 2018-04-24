#include<bits/stdc++.h>
using namespace std;
int num=0;
void print(int ** arr,int n,int m){
    if(num>2)
        return;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    num++;
    print(arr,n,m);
}
int main(){
    int n,m;
    cin>>n>>m;
    int **arr=(int**)malloc(n*sizeof(int));
    for(int i=0;i<m;i++)
        arr[i]=(int*)malloc(m*sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
   print(arr,n,m);
    return 0;
}
