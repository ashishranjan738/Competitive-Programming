#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        bool flag=1;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        map<vector<int>,bool> m;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int temp1=j+1,temp2=n-1;
                while(temp1<temp2){
                    vector<int> v;
                    if(arr[i]+arr[j]+arr[temp1]+arr[temp2]==k){
                        v.push_back(arr[i]);
                        v.push_back(arr[j]);
                        v.push_back(arr[temp1]);
                        v.push_back(arr[temp2]);
                        if(!m[v])cout<<arr[i]<<" "<<arr[j]<<" "<<arr[temp1]<<" "<<arr[temp2]<<" $";
                        m[v]=1;
                        temp2--;
                        temp1++;
                        flag=0;
                    }
                    else if(arr[temp1]+arr[temp2]>k-arr[i]-arr[j])
                        temp2--;
                    else if(arr[temp1]+arr[temp2]<k-arr[i]-arr[j])
                        temp1++;
                }
            }
        }
        if(flag)cout<<"-1";
        cout<<endl;
    }

    return 0;
}
