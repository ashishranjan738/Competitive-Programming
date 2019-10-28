#include<bits/stdc++.h>
using namespace std;
#define vc vector
#define pb push_back
bool comp(vector<int> a,vector<int> b){
    return a[0]<b[0];
}
int solution(vc<vc<int>> &v,vc<int> prev,int i){
    if(i>=v.size())
        return 0;
    else if(prev.size()==0)
        return max(1+solution(v,v[i],i+1),solution(v,v[i+1],i+2));
    if(prev[1]>=v[i][0])
        return solution(v,prev,i+1);
    else if(prev[1]<v[i][0])
        return max(1+solution(v,v[i],i+1),solution(v,prev,i+1));
}
int main(){
    int n;
    cin>>n;
    vc<vc<int>> v;
    for(int i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        v.push_back({t1,t2});
    }
    sort(v.begin(),v.end(),comp);
    cout<<solution(v,{},0);
    return 0;
}