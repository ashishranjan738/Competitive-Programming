#include<bits/stdc++.h>
using namespace std;
int xorsumequal(int n){
    int unsetbits=0;
    while(n){
        unsetbits+=!(n&1);
        n>>=1;
    }
    return 1<<unsetbits;
}
int main(){
    int n;
    cin>>n;
    cout<<xorsumequal(n);
    return 0;
}
