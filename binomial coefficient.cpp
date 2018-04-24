#include<bits/stdc++.h>
using namespace std;
int calBinomial(int n,int k){
    if(k==n||k==0)
        return 1;
    else if(k>0&&k<n)return calBinomial(n-1,k)+calBinomial(n-1,k-1);
    else return 0;
}
int calBinomialDP(int n,int k){
    int sol[n+1][k+1];
    //memset(sol,0,sizeof(sol));
    for(int i=0;i<=k;i++)
        sol[0][i]=1;
    for(int j=0;j<=n;j++)
        sol[j][0]=1;
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=k;j++)
//            cout<<sol[i][j]<<" ";
//        cout<<endl;
//    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=min(i,k);j++){
            if(j==0||j==i)
                sol[i][j]=1;
            else sol[i][j]=sol[i-1][j-1]+sol[i-1][j];
        }
    }
    return sol[n][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<calBinomialDP(n,k);
    return 0;
}
