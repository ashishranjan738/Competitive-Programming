#include<bits/stdc++.h>
using namespace std;
struct node{
    int color,parent;
};
int main(){
    int n,k;
    cin>>n>>k;
    node arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].color;
        arr[i].parent=-1;
    }
    int temp[2];
    for(int i=0;i<n-1;i++){
        cin>>temp[0]>>temp[1];
        sort(temp,temp+2);
        arr[temp[1]-1].parent=temp[0]-1;
    }
    for(int i=0;i<n;i++){
        int progress=k-1,ptr=arr[i].parent;
        while(1){
            if(arr[ptr].color==arr[i].color&& !progress){
                cout<<ptr+1<<" ";
                break;
            }
            else if(arr[ptr].parent==-1 || !progress){
                cout<<"-1 ";
                break;
            }
            else{
                progress--;
                ptr=arr[ptr].parent;
            }
        }
    }
    return 0;
}
