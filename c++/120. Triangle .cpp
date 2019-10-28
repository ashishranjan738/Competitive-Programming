#include <bits/stdc++.h>
using namespace std;
#define vc vector
#define pb push_back
int solution(vc<vc<int>> &v,int i,int j,int sum,int level){
    //cerr<<"level :"<<level<<endl;
    //cerr<<"i :"<<i<<" j :"<<j<<endl;
    //cout<<v[i][j];
    if(level==v.size())
        return sum;
    else
        return min(solution(v,i+1,j,sum+v[i][j],level+1),solution(v,i+1,j+1,sum+v[i][j],level+1));
}
int solutionDp(vc<vc<int>> &v){
    vc<vc<int>> dp;
    for(int i=0;i<v.size();i++)
        dp.pb(vc<int> (i+1,0));
    for(int i=0;i<v[v.size()-1].size();i++)
        dp[v.size()-1][i]=v[v.size()-1][i];
    for(int i=v.size()-2;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            dp[i][j]=min(dp[i+1][j]+v[i][j],dp[i+1][j+1]+v[i][j]);
        }
    }
    return dp[0][0];
}
int solutionDPOptimized(vc<vc<int>> &v){
    vc<int> dp=v[v.size()-1];
    //cerr<<dp.size();
    for(int i=v.size()-2;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            dp[j]=min(dp[j]+v[i][j],dp[j+1]+v[i][j]);
        }
    }
    return dp[0];
}
int main(){
    int n;
    cin>>n;
    vc<vc<int>> v;
    for(int i=0;i<n;i++){
        vc<int> vt(i+1);
        for(int &j:vt)
            cin>>j;
        v.push_back(vt);
    }
    cout<<solutionDPOptimized(v);
    //cout<<solutionDp(v);
    //cout<<solution(v,0,0,0,0);
    return 0;
}