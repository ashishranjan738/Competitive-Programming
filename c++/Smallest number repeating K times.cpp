#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        unordered_map<int,int> map;
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            map[arr[i]]++;
        }
        bool flag=false;
        int minimum=INT_MAX,first;
        unordered_map<int,int>::iterator it;
        for(it=map.begin();it!=map.end();it++){
            if(it->second==k){
                minimum=min(minimum,it->first);
                flag=true;
            }
        }
        flag?cout<<minimum<<endl:cout<<"-1\n";
    }
    return 0;
}
