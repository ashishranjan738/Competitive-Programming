#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(char ch:s){
        if(isupper(ch))
            cout<<char(int(ch+k-65)%26 +65);
        else if(islower(ch))
            cout<<char(int(ch+k-97)%26 +97);
        else cout<<ch;
    }
    return 0;
}
