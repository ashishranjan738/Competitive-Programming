#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int sum=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1])
                sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

