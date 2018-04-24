#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int t1=j+1,t2=n-1;
                int val=k-arr[i]-arr[j];
                while(t1<t2){
                    if(arr[t1]+arr[t2]==val){
                        cout<<arr[i]<<" "<<arr[j]<<" "<<arr[t1]<<" "<<arr[t2]<<"$";
                        t1++;
                        t2--;
                    }
                    else if(arr[t1]+arr[t2]>val)
                        t2--;
                    else
                        t1++;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
