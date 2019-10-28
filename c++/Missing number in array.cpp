#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=i+1;
        int temp=0;
        for(int i=0;i<n-1;i++){
            cin>>temp;
            sum-=temp;
        }
        cout<<sum;
    }
    return 0;
}
