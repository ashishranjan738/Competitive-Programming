#include<bits/stdc++.h>
#define pb push_back
#define vc vector
using namespace std;
int lcsdp(vc<int> &nums){
    if(!nums.size())
        return 0;
    vector<int> dp(nums.size(),1);
    int maxt=1;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                if(maxt<dp[i])
                    maxt=dp[i];
            }
        }
    }
    for(int i:dp)
        cout<<i<<" ";
    cout<<endl;
    return maxt;
}
int lcs(vc<int> &v,int prev,int i){
    if(i==v.size())
        return 0;
    return max(v[i]>prev?1+lcs(v,v[i],i+1):0,lcs(v,prev,i+1));
}
int findNumberOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(),1);
    map<int,int> m;
    int maxt=1;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[i]<=dp[j]+1){
                if(dp[i]==dp[j]+1)
                    m[i]++;
                dp[i]=dp[j]+1;
                if(maxt<dp[i])
                    maxt=dp[i];
            }
        }
    }
    int temp=0;
    cout<<"dp"<<endl;
    for(int i:dp)
        cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<dp.size();i++){
        cout<<m[i]<<" ";
        if(dp[i]==maxt){
            temp+=m[i];
        }
    }
    cout<<endl<<"maxt :"<<maxt;
    cout<<endl<<"value :"<<temp+1;
    return temp;
}
int main(){
    int n;
    cin>>n;
    vc<int> v(n);
    for(int &i:v)
        cin>>i;
    findNumberOfLIS(v);
    return 0;
}