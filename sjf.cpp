#include<bits/stdc++.h>
using namespace std;
struct job{
    int id;
    int bt;
    int at;
};
bool comp(job a,job b){
    return a.bt<b.bt;
}
int main(){
int n;
cout<<"Enter the number of job \n";
cin>>n;
job arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i].bt;
    arr[i].id=i+1;
    arr[i].at=i;
}
sort(arr,arr+n,comp);
cout<<"Process ID             Brust Time                   Waiting Time \n";
int wt=0;
for(int i=0;i<n;i++){
    cout<<arr[i].id<<"                      "<<arr[i].bt<<"                            "<<wt<<endl;
    wt=wt+arr[i].bt;
}
return 0;}
