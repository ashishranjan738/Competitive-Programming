#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,p,q,r;
    cin>>n>>p>>q>>r;
    long long int arr1[n];
    long long int arr2[n];
    long long int arr3[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
        arr2[i]=q*arr1[i];
        arr3[i]=r*arr1[i];
        arr1[i]*=p;
    }
    long long int sum1=INT_MIN,sum2=INT_MIN,sum3=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr1[i]>sum1)
            sum1=arr1[i];
    }
    for(int i=0;i<n;i++){
        if(arr2[i]>sum2)
            sum2=arr2[i];
    }
    for(int i=0;i<n;i++){
        if(arr3[i]>sum3)
            sum3=arr3[i];
    }
    cout<<sum1+sum2+sum3<<endl;
    return 0;
}
