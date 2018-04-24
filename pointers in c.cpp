#include<bits/stdc++.h>
using namespace std;
int square(int a){
    return a*a;
}
int main(){
    int (*fptr)(int);
    fptr=square;
    cout<<fptr(6);

return 0;}
