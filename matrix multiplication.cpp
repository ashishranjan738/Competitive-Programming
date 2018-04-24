#include<bits/stdc++.h>
using namespace std;
void multiplication();
void display(int **a,int m,int n){

}
int main(){
    int n,m;
    cin>>n>>m;
    int **a=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<m;i++)
        a[i]=(int*)malloc(sizeof(int));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    int n1,m1;
    cin>>n1>>m1;
    int **a1=(int **)malloc(n1*sizeof(int*));
    for(int i=0;i<m1;i++)
        a1[i]=(int*)malloc(sizeof(int));
    for(int i=0;i<n1;i++)
        for(int j=0;j<m1;j++)
            cin>>a1[i][j];

    int **a2=int(**)malloc(n*sizeof(int));
    for(int i=0;i<m1;i++)
        a2[i]=(int *)malloc(sizeof(int));

    for(int i=0;i<n;i++){
        for(int j=0;j<m1;j++){
            a2[i][j]=0;
            for(int k=0;k<m;k++){
                a2[i][j]=a2[i][j]+(a[i][k]*a1[k][j]);
            }
        }
    }

}
