#include<bits/stdc++.h>
using namespace std;
//void displayMat(int mat[],int m,int n){
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<mat[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}
//int editDistances(int mat[a.lenght()+1][b.length()+1],int m,int n,string &a,string &b){
//    for(int i=1;i<m;i++){
//        for(int j=1;j<m;j++){
//            if(a[i-1]==b[j-1]){
//                mat[i][j]==mat[i-1][j-1];
//            }
//            else{
//                mat[i][j]=min(mat[i-1][i-1],min(mat[i][j-1],mat[i-1][j]))+1;
//            }
//        }
//    }
//    //display(mat,m,n);
//    return mat[a.length()][b.length()];
//}
int main(){
    string a,b;
    cin>>a>>b;
    int  mat[a.length()+1][b.length()+1]={0};
    for(int i=0;i<b.length()+1;i++)
        mat[0][i]=i;
    for(int i=0;i<a.length()+1;i++)
        mat[i][0]=i;
    cout<<a<<endl<<b<<endl ;
    for(int i=1;i<a.length()+1;i++){
        for(int j=1;j<b.length()+1;j++){
            //cout<<a[i-1]<<" "<<b[j-1]<<endl;
            if(a[i-1]==b[j-1]){
                mat[i][j]=mat[i-1][j-1];
            }
            else{

                mat[i][j]=(min(mat[i-1][j-1],min(mat[i][j-1],mat[i-1][j])))+1;
            }
        }
    }
    for(int i=0;i<a.length()+1;i++){
        for(int j=0;j<b.length()+1;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<mat[a.length()][b.length()];
return 0;}
