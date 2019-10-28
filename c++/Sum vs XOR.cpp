#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned long long int n;
    cin>>n;
    long long int count=0;
    while(n){
        count+=!(n&1);
        n>>=1;
    }
    cout<<(1LL<<count)<<endl;
    return 0;
}
