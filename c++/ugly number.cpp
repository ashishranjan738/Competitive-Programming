#include<bits/stdc++.h>
using namespace std;
int maxDivide(int no,int b){
    while(!(no%b)){
        no/=b;
    }
    return no;
}
bool isUgly(int no){
    no=maxDivide(no,2);
    no=maxDivide(no,3);
    no=maxDivide(no,5);
    return (no==1)?1:0;
}
unsigned int isUglyDp(int n){
    unsigned int sol[n];
    sol[0]=1;
    int it1,it2,it3;
    it1=it2=it3=0;
    for(int i=1;i<n;i++){
        unsigned int ans=min(sol[it1]*2,min(sol[it2]*3,sol[it3]*5));
        sol[i]=ans;
        if(ans==(sol[it1]*2))
            it1++;
        if(ans==sol[it2]*3)
            it2++;
        if(ans==sol[it3]*5)
            it3++;
    }
    return sol[n-1];
}
int main(){
    int no;
    cin>>no;
    cout<<isUglyDp(no);
    return 0;
}
