#include<bits/stdc++.h>
using namespace std;
int main(){
int arr[26];
memset(arr,0,sizeof(arr));
string s;
cin>>s;
for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
}
int t;
cin>>t;
while(t--){
    int q;
    cin>>q;
    bool flag=false;
    for(int i=0;i<26;i++){
        if(q%(i+1)==0){
            int temp=q/(i+1);
            if(temp<=arr[i]){
                flag=true;
                break;
            }
        }
    }
    flag?cout<<"Yes\n":cout<<"No\n";
}

return 0;}
