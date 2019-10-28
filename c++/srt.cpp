#include<bits/stdc++.h>
using namespace std;
struct job{
    int at;
    int id;
    int bt;
    bool finished;
};
int givemin(job arr[],int n,int time){
    int mini=-1;
    for(int i=0;i<n;i++){
        if(!arr[i].finished&&arr[i].at<=time){
            mini=i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(!arr[i].finished&&arr[i].at<=time){
            if(arr[mini].bt>arr[i].bt){
                    mini=i;
            }
        }
    }
    if(mini==-1){
        int time=INT_MAX;
        for(int i=0;i<n;i++){
            if(!arr[i].finished)
            if(time>arr[i].at){
                time=arr[i].at;
                mini=i;
            }
        }
    }
    return mini;
}
int main(){
int n;
cout<<"Enter the number of processes";
cin>>n;
int t=n;
job arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i].at>>arr[i].bt;
    arr[i].id=i+1;
    arr[i].finished=false;
}
cout<<"Process ID          Brust time              Waiting time              Arrival time           Turn around time  \n";
int time=0;
int wt=0;
while(t--){
    int next=givemin(arr,n,time);
    arr[next].finished=true;
    cout<<arr[next].id<<"                "<<arr[next].bt<<"                   "<<wt<<"                     "<<arr[next].at<<"             "<<wt+arr[next].bt-time<<endl;
    wt=wt+arr[next].bt;
    time=max(time,arr[next].at+arr[next].bt);
}
return 0;}
