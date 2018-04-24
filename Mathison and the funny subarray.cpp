#include<bits/stdc++.h>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x:v)
        cin>>x;
    map<int,vector<int>> mp;
    for(auto i=0;i<v.size();i++)
        mp[v[i]].push_back(i);
    int sum=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        if(sum<(*it).second[((*it).second).size()-1]-(*it).second[0]);
            sum=(*it).second[((*it).second).size()-1]-(*it).second[0];
    }

    cout<<sum+1;
    return 0;
}
