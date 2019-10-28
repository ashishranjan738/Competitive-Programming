#include<bits/stdc++.h>
using namespace std;
//bute force method
int calMaxLength(string &s){
    int len=s.length();
    int maxlen=0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j+=2){
            int templen=j-i+1;
            //cout<<"templen: "<<templen<<endl;
            if(templen<maxlen)
                continue;
            else{
                int lsum=0,rsum=0;
                for(int k=0;k<templen/2;k++){
                    lsum+=s[i+k]-'0';
                    rsum+=s[i+templen/2+k]-'0';
                    //cout<<s[i+k]<<" "<<s[i+templen/2+k]<<endl;
                }
                //cout<<"lsum"<<lsum<<" rsum"<<rsum<<endl;
                if(lsum==rsum)
                    maxlen=templen;
            }
        }
    }
    return maxlen;
}
int calMaxLengthDP(string &s){
    int len=s.length();
    int arr[len][len];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<len;i++)
        arr[i][i]=str[i]-'0';
    for(int templen=2;templen<=len;templen++){

    }
}
int main(){
    string s;
    cin>>s;
    cout<<calMaxLength(s);
    return 0;
}
