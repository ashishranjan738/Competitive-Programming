#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    int count=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int d,m;
    cin>>d>>m;
    for(int i=0;i+m<=n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum+=arr[i+j];
        }
        if(sum==d)
            count++;
    }
    cout<<count;
    return 0;
}
