#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int correct=0;
    int x=0,y=0;
    for(int i=0;i<n;i++){
        if(s[i]=='L')
            x--;
        else if(s[i]=='R')
            x++;
        else if(s[i]=='U')
            y++;
        else if(s[i]=='D')
            y--;
        if(x==0 && y==0){
            correct=i+1;
            break;
        }
    }
    cout<<correct;
    return 0;
}
