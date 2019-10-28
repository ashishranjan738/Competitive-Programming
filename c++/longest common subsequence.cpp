#include<bits/stdc++.h>
using namespace std;
int lcs(string a,string b){
    if(!a.length()&&!b.length())
        return 0;
    else if((a.length()&&!b.length())||(!a.length()&&b.length()))return 0;
    else{
        if(a[0]!=b[0]) return max(lcs(a.substr(1),b),lcs(a,b.substr(1)));
        else return 1+lcs(a.substr(1),b.substr(1));
    }
}
int lcsDP(string a,string b){
    int alen=a.length(),blen=b.length();
    int sol[alen+1][blen+1];
    memset(sol,0,sizeof(sol));
    for(int i=1;i<=alen;i++){
        for(int j=1;j<=blen;j++){
            if(a[i-1]==b[j-1])
                sol[i][j]=sol[i-1][j-1]+1;
            else sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
        }
    }
    return sol[alen][blen];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcsDP(s1,s2);
    return 0;
}
