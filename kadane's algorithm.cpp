#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int maxSumEndingHere=0;
    int maxSumSoFar=0;
    for(int i=0;i<n;i++){
            maxSumEndingHere+=arr[i];
        if(maxSumEndingHere<0)
            maxSumEndingHere=0;
        if(maxSumSoFar<maxSumEndingHere)
            maxSumSoFar=maxSumEndingHere;

    }
    cout<<maxSumSoFar<<endl;
    return 0;
}
