#include<bits/stdc++.h>
using namespace std;
struct doctor{
    int w,wd;
};
int main(){
        int n;
        cin>>n;
        doctor arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].w>>arr[i].wd;
        }
        for(int i=1;i<n;i++){
            if(arr[i].w>arr[i-1].w)
                continue;
            else{
                for(;arr[i].w<arr[i-1].w || arr[i].w==arr[i-1].w;arr[i].w+=arr[i].wd);
            }
            //cout<<arr[i].w<<" ";
        }
        cout<<arr[n-1].w<<endl;
    return 0;
}
