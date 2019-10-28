#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int len=0;
    for(int i=0;i<n;i++){
        len+=arr[i];
        if(i!=n-1)
            len++;
    }
    (len==x)?cout<<"YES \n":cout<<"NO \n";
    return 0;
}
