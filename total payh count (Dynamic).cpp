#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int mat[m][n]={0};
    for(int i=1;i<m;i++){
        mat[0][i]=1;
    }
    for(int i=1;i<n;i++){
        mat[i][0]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            mat[i][j]=mat[i-1][j]+mat[i][j-1];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<mat[m-1][n-1];
return 0;}
