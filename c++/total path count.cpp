#include<bits/stdc++.h>
using namespace std;
int countPath(int n,int m){
    if(n==0&&m==0)
        return 0;
    else if(n==0&&m>0)
        return 1;
    else if(n>0&&m==0)
        return 1;
    else return countPath(n-1,m)+countPath(n,m-1);
}
int countPathDP(int n,int m){
    int arr[n+1][m+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++)
        arr[i][0]=1;
    for(int i=1;i<=m;i++)
        arr[0][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=m;j++){
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return arr[n][m];
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<countPathDP(n,m);
    return 0;
}
