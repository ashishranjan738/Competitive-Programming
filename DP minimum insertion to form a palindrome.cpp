#include<bits/stdc++.h>
using namespace std;
int findMinInsertions(char str[],int l,int h){
    if(l>h)return INT_MAX;
    else if(l==h)return 0;
    else if(l==h-1)return (str[l]==str[h])?0:1;
    else if(str[l]==str[h])return findMinInsertions(str,l+1,h-1);
    else return min(findMinInsertions(str,l+1,h),findMinInsertions(str,l,h-1))+1;
}

int findMinInsertionsDP(char str[],int n){
    int table[n][n];
    memset(table,0,sizeof(table));
    int l,h,len;
    for(len=1;len<n;len++){
        for(h=len,l=0;h<n;l++,h++){
            table[l][h]=(str[l]==str[h])?table[l+1][h-1]:min(table[l+1][h],table[l][h-1])+1;
        }
    }
    return table[0][n-1];
}
int main(){
char str[]="ashishl;ekrjglermb'rtbm;lkrtmkmrtnmrtkmrktmnkrnt'ml;ekmcsdmv;mermb,,mdfbmrt'm;'dmfkkmrth'msd'rmgermh;'rtlmh;lrmt;'hme;rmherkm;lrmgremgrkejhrmh;lk";
cout<<findMinInsertions(str,0,strlen(str)-1);
return 0;}
