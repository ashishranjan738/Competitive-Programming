#include<bits/stdc++.h>
using namespace std;
int main() {
    long long int type[5]={0};
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        type[arr[i]-1]++;
    }
    long long int max=INT_MIN;
    for(int i=0;i<5;i++){
        if(max<type[i])
            max=type[i];}
    for(int i=0;i<5;i++){
        if(max==type[i])
            cout<<i+1
    }
    return 0;
}
