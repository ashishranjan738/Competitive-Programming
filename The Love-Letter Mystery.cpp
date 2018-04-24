#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,s1;
        cin>>s;
        s1=s;
        reverse(s1.begin(),s1.end());
        int sum=0;
        bool flag=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=s1[i]){
                flag=1;
                sum+=abs(s[i]-s1[i]);
            }
        }
        flag?cout<<sum/2<<endl:cout<<"0\n";
    }
    return 0;
}
