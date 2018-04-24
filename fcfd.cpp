#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct job{
    int job_id;
    int bt;
};
int main(){
cout<<"Enter the number of processe \n";
int n;
cin>>n;
queue<job> q;
for(int i=0;i<n;i++){
    job temp;
    cin>>temp.bt;
    temp.job_id=i+1;
    q.push(temp);
}
cout<<"Process ID             Brust Time                   Waiting Time \n";
int wt=0;
while(!q.empty()){
    job temp=q.front();
    q.pop();
    cout<<temp.job_id<<"                      "<<temp.bt<<"                            "<<wt<<endl;
    wt=wt+temp.bt;
}
return 0;}
