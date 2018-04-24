#include<bits/stdc++.h>
using namespace std;
map<long long int,bool> primet;
map<long long int,bool> m;
bool prime[10000009];
void SieveOfEratosthenes(){
    int n=10000009;
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if(prime[p]){
           primet[p]=true;
       }
}
int main(){
    int t;
    SieveOfEratosthenes();
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string temp;
        int countt=0;
        for(int i=0;i<s.length();){
            if(isdigit(s[i])){
                while(i<s.length() && isdigit(s[i])){
                    temp.push_back(s[i]);
                    i++;
                }
                long long int num=stoll(temp);
                temp.clear();
                if(primet[num]){
                        countt++;
                    m[num]=true;
                }
            }
            else i++;
        }
        long long int maxt=INT_MIN;
        for(auto it=m.begin();it!=m.end();it++){
            if((*it).first>maxt)maxt=(*it).first;
        }
        if(!countt)cout<<"-1"<<endl;
        else cout<<countt<<" "<<maxt<<endl;
        m.clear();
    }
    return 0;
}
