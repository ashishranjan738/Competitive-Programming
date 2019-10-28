#include<Bits/stdc++.h>
using namespace std;
int editDistances(const string &a,const string &b){
    if(!a.length()&&!b.length())
        return 0;
    if(!a.length()&&b.length()){
        return b.length();
    }
    else if(!b.length()&&a.length()){
        return a.length();
    }
    else if(a[0]==b[0]) return editDistances(a.substr(1),b.substr(1));
    int p,q,r;
    p=editDistances(a,b.substr(1));
    q=editDistances(a.substr(1),b.substr(1));
    r=editDistances(a,b.substr(1));
return min(p,min(q,r))+1;
}
int editDistancesDP(const string &a,const string &b){
    int arr[a.length()+1][b.length()+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=b.length();i++)
        arr[0][i]=i;
    for(int j=1;j<=a.length();j++)
        arr[j][0]=j;
    for(int i=1;i<=a.length();i++){
        for(int j=1;j<=b.length();j++){
            if(a[i-1]==b[j-1])
                arr[i][j]=arr[i-1][j-1];
            else arr[i][j]=min(arr[i-1][j],min(arr[i-1][j-1],arr[i][j-1]))+1;
        }
    }
//    for(int i=0;i<a.length()+1;i++){
//        for(int j=0;j<b.length()+1;j++){
//            cout<<arr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return arr[a.length()][b.length()];
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<editDistancesDP(a,b);
return 0;}
