
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,w;
    cin>>n>>w;
    int arr[n],arrh[n],arrk[n];
    memset(arrk,0,sizeof(arrk));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++)
        arrh[i]=ceil((double)arr[i]/2);
    bool flag=0;
    for(int i=0;i<n;i++){
        w=w-arrh[i];
        if(w<0){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"-1";return 0;}
    for(int i=0;i<n;i++){
        arrk[i]=arr[i]-arrh[i];
    }
    //cout<<w;
    for(int i=0;i<n;i++){
        if(w>=arrk[i])
           w=w-arrk[i];
        else{
            arrk[i]=w;
            w=0;
            for(int j=i+1;j<n;j++)
                arrk[j]=0;
            break;
        }
    }
    if(w>0)
        flag=1;
    else {for(int i=0;i<n-1;i++)
        if(arrh[i+1]+arrk[i+1]>arrh[i]+arrk[i]){
            flag=1;
            break;
        }}
    if(flag){
        cout<<"-1";return 0;}
    for(int i=0;i<n;i++)
        cout<<arrh[i]+arrk[i]<<" ";
return 0;}
