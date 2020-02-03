#include<bits/stdc++.h>
using namespace std;
bool solve(string a,string b,string c){
    vector<vector<bool>> dp(a.length()+1,vector<bool> (b.length()+1,0));
    dp[0][0]=1;
    for(int i=1;i<=a.length();i++)
        if(a[i-1]==c[i-1])dp[i][0]=dp[i-1][0];
    for(int i=1;i<=b.length();i++)
        if(b[i-1]==c[i-1])dp[0][i]=dp[0][i-1];

    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(c[i+j-1]==a[i-1])
                dp[i][j]=dp[i][j]|dp[i-1][j];
            if(c[i+j-1]==b[j-1])
                dp[i][j]=dp[i][j]|dp[i][j-1];
        }
    }
    return dp[a.length()][b.length()];
}


int main(){
    string a="bcc";
    string b="bbca";
    string c="bbcbcac";
    cout<<solve(a,b,c);
    return 0;
}