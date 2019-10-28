#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   int a1,a2,a3;
   int b1,b2,b3;
   cin>>a1>>a2>>a3>>b1>>b2>>b3;
    int p1=0,p2=0;
    if(a1!=b1)a1>b1?p1++:p2++;
    if(a1!=b1){a2>b2?p1++:p2++;cout<<"sdjflskdf";}
    if(a1!=b1)a3>b3?p1++:p2++;
    cout<<p1<<" "<<p2;
    return 0;
}
