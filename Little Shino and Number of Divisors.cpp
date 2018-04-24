#include<bits/stdc++.h>
using namespace std;
struct node{
    int pNo,power;
    node(int a){
        pNo=a;
        power=0;
    }
};
bool isPrime(unsigned long long int number)
{
    for (unsigned long long int i = 3; (i*i) <= number; i += 2){
        if (number % i == 0)
            return false;
    }
    return true;
}
vector<node> nPrime(unsigned int n){
    vector<node> v;
    if(n>0){
        node a(2);
        v.push_back(a);
    }
    unsigned int counter = 1;
    unsigned long long int number = 1;
    while (counter < n)
    {
        number += 2;
        if(isPrime(number)){
            node a(number);
            v.push_back(a);
            counter++;
        }
    }
    return v;
}
int main(){
    int a;
    cin>>a;
    vector<node> prime=nPrime(a);
    unsigned int mod=pow(10,9)+7;
    unsigned long long int nf=1,n=1,pf;
    for(int i=0;i<a;i++){
        cin>>prime[i].power;
        n =(n%mod*((int)pow(prime[i].pNo,prime[i].power)%mod))%mod;
        nf=((nf%mod)*((prime[i].power+1)%mod))%mod;
        prime[i].power=0;
    }
    pf=pow(n,nf/2)%mod;
    int i;
    nf=1;
    for(i=0;i<prime.size()&&pf;i++){
        while(pf&&!(pf%prime[i].pNo)){
            prime[i].power++;
            pf/=prime[i].pNo;
        }
        if(prime[i].power){
            nf=((nf%mod)*((int)(prime[i].power+1)%mod))%mod;
        }
    }
    cout<<nf%mod;
    return 0;
}
