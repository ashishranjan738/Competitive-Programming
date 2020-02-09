#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            q.push(x);
        }
        int sum=0;
        while(q.size()>1){
            int x1=q.top();
            q.pop();
            int x2=q.top();
            q.pop();
            sum+=x1+x2;
            q.push(x1+x2);
        }
        cout<<sum<<endl;
    }
    return 0;
}