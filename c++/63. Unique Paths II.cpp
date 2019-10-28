#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vc vector
int uniquePath(vc<vc<int>> &v,int i,int j){
    if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]==1)
        return 0;
    else if(i==v.size()-1 && j==v[0].size()-1)
        return 1;
    return uniquePath(v,i+1,j)+uniquePath(v,i,j+1);
}
int uniquePathDp(vector<vector<int>> &v){
    vector<vector<int>> dp(v.size(),vector<int> (v[0].size(),0));
    for(int i=0;i<v.size();i++){
        if(i==0)
            dp[0][0]=1;
        if(v[i][0]==1)
            dp[i][0]=0;
        else if(i!=0 && dp[i-1][0]!=0 && v[i][0]==0)
            dp[i][0]=1;
    }
    for(int i=0;i<v[0].size();i++){
        if(i==0)
            dp[0][0]=1;
        if(v[0][i]==1)
            dp[0][i]=0;
        else if(i!=0 && dp[0][i-1]!=0 && v[0][i]==0)
            dp[0][i]=1;
    }
//    cout<<"dp \n";
//    for(vc<int> i:dp){
//        for(int j:i)
//            cout<<j<<" ";
//        cout<<endl;
//    }
//    cout<<"end"<<endl;
    for(int i=1;i<v.size();i++){
        for(int j=1;j<v[0].size();j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
//    cout<<"dp \n";
//    for(vc<int> i:dp){
//        for(int j:i)
//            cout<<j<<" ";
//        cout<<endl;
//    }
//    cout<<"end"<<endl;
    return dp[v.size()-1][v[0].size()-1];
}
int main(){
    int n;
    cin>>n;
    vc<vc<int>> v(n,vc<int> (n,0));
    for(vc<int> &i:v)
        for(int &j:i)
            cin>>j;
    cout<<"Value:"<<uniquePathDp(v);
    //cout<<"value :"<<uniquePath(v,0,0);
    return 0;
}