#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int> &v,vector<int> &subsetSumArr,vector<bool> &taken,int subsetsum,int k,int idx,int lastidx){
    if(subsetSumArr[idx]==subsetsum){
        if(idx==k-2)
            return true;
        else return helper(v,subsetSumArr,taken,subsetsum,k,idx+1,v.size()-1);
    }
    else{
        for(int i=lastidx;i>=0;i--){
            if(taken[i])
                continue;
            if(subsetSumArr[idx]+v[i]<=subsetsum){
                taken[i]=true;
                subsetSumArr[idx]+=v[i];
                if(helper(v,subsetSumArr,taken,subsetsum,k,idx,i-1))
                    return true;
                taken[i]=false;
                subsetSumArr[idx]-=v[i];
            }
        }
    }
    return false;
}
bool isPartitionedPossible(vector<int> &v,int k){
    if(k==1)
        return true;
    else if(v.size()<k)
        return  false;
    int sum=0;
    for(int i:v)
        sum+=i;
    if(sum%k!=0)
        return false;
    int subsetSum=sum/k;
    vector<int> subsetSumArr(k,0);
    vector<bool> taken(v.size(),false);
    subsetSumArr[0]+=v[v.size()-1];
    taken[v.size()-1]=true;
    return helper(v,subsetSumArr,taken,subsetSum,k,0,v.size()-1);
}
int main(){
    vector<int> v={4,3,2,3,5,2,1};
    int k=4;
    cout<<isPartitionedPossible(v,k);
    return 0;
}