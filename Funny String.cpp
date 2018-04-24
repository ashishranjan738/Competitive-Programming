#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
    string sb;
    for(int i=s.length()-1;i>=0;i--){
        sb.push_back(s[i]);
    }
    bool flag=false;
    for(int i=0;i<=s.length();i++){
        cout<<s[i+1]-s[i]<<" "<<sb[i+1]-sb[i]<<endl;
        if(abs(s[i+1]-s[i])!=abs(sb[i+1]-sb[i])){
            flag=1;
            break;
        }
    }
    flag?cout<<"Not Funny\n":cout<<"Funny\n";
}
return 0;}
