#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a1(n);
    map<int,int> m;
    for(int i=0;i<n;i++)
        cin>>a1[i];
    int mn;
    cin>>mn;
    vector<int> a2(mn);
    for(int i=0;i<mn;i++){
        cin>>a2[i];
        m[a2[i]]++;
    }
    for(int i=0;i<n;i++){
        m[a1[i]]--;
    }
    vector<int> v;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second>0)
            v.push_back(it->first);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
