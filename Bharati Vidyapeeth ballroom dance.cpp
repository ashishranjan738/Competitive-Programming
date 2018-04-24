#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arrm[n];
    for(int i=0;i<n;i++)
        cin>>arrm[i];
    int m;
        cin>>m;
    int arrg[m];
    for(int i=0;i<m;i++)
        cin>>arrg[i];
    sort(arrm,arrm+n);
    sort(arrg,arrg+m);
    int sum=0;
    int i=0,j=0;
    while(i<n&&j<m){
        if(abs(arrm[i]-arrg[j])<=1){
            i++;
            j++;
            sum++;
        }
        else if(arrm[i]-arrg[j]<-1)
            i++;
        else if(arrm[i]-arrg[j]>1)
            j++;
    }
    cout<<sum;
    return 0;
}
