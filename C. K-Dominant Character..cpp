#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int i;
    for(i=1;i<100000;i++){
        bool arr[26]={0};
        for(int j=0;j<i;j++){
            arr[s[j]-'a']=true;
        }
        for(int j=i;j<s.length();j+=i){
            bool temp[26]={0};
            for(int k=j;k<s.length() && k<j+i;k++){
                temp[s[k]-'a']=true;
            }
            for(int l=0;l<26 ;l++){
                if(!temp[l] && arr[l])
                    arr[l]=false;
            }
        }
        for(int l=0;l<26;l++){
            if(arr[l]){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    return 0;
}
