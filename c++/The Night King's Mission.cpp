#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int pos=0;
    while(pos<n){
        if(arr[pos+2])
            pos+=2;
        else if(arr[pos+3])
            pos+=3;
        else break;
    }
    pos>=n?cout<<'1':cout<<'0';
    return 0;
}
