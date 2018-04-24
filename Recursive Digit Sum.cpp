#include<bits/stdc++.h>
using namespace std;
long long int super(long long int num){
    if(num/10==0)
        return num;
    long long int temp=0;
    while(num){
        temp+=num%10;
        num/=10;
    }
    return super(temp);
}
int main(){
    string n;
    int k;
    cin>>n>>k;
    long long int p=0;
    for(int i=0;i<n.length();i++){
        p+=(n[i]-'0')*k;
    }
    cout<<super(p);
    return 0;
}

