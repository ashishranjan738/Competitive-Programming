#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//    int n;
//    cin>>n;
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(char ch:s){
        if(ch>=65&&ch<=90){
            int temp=(int)ch+k;
            if(temp>90){
                temp=temp%90+64;
                cout<<(char)temp;
            }
            else cout<<(char)(ch+k);
        }
        else if(ch>=97&&ch<=122){
            int temp=(int)ch+k;
            if(temp>122){
                temp=temp%26;
                //cout<<temp;
                cout<<(char)(temp+97);
            }
            else cout<<(char)(ch);
        }
        else cout<<ch;
    }
    return 0;
}
