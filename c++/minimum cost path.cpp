#include<bits/stdc++.h>
using namespace std;
int mem[100][100]={0};
int calMin(vector<vector<int>> &mat,int n,int m){
    if(n==0&&m==0)
        return mat[0][0];
    else if(m==0)
        return calMin(mat,n-1,m)+mat[n][m];
    else if(n==0)
        return calMin(mat,n,m-1)+mat[n][m];
    else return min(calMin(mat,n,m-1),calMin(mat,n-1,m))+mat[n][m];
}
int calMinMem(vector<vector<int>> mat,int n,int m){
    if(mem[n][m]!=0)
        return mem[n][m];
    if(n==0&&m==0)
        mem[n][m]=mat[0][0];
    else if(m==0)
        mem[n][m]=calMin(mat,n-1,m)+mat[n][m];
    else if(n==0)
        mem[n][m]=calMin(mat,n,m-1)+mat[n][m];
    else mem[n][m]=min(calMin(mat,n,m-1),calMin(mat,n-1,m))+mat[n][m];
    return mem[n][m];
}
int calMinDp(vector<vector<int>> mat,int n,int m){
    memset(mem,0,sizeof(mem));
    mem[0][0]=mat[0][0];
    for(int i=1;i<=m;i++){
        mem[0][i]=mem[0][i-1]+mat[0][i];
    }
    for(int i=1;i<=n;i++){
        mem[i][0]=mem[i-1][0]+mat[i][0];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mem[i][j]=min(mem[i-1][j],mem[i][j-1])+mat[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<mem[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    calMinDp(mat,n-1,m-1);
    return 0;
}
