#include<bits/stdc++.h>
using namespace std;
struct IceCream{
    int flavor;
    int index;
};
bool compare(IceCream a,IceCream b){
    return a.flavor<b.flavor;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        IceCream arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].flavor;
            arr[i].index=i+1;
        }
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i].flavor+arr[j].flavor==m){
                    cout<<arr[i].index<<" "<<arr[j].index<<endl;
                }
            }
        }
    }
    return 0;
}
