#include<bits/stdc++.h>
using namespace std;
struct Pos1{
int x,y;
};
int main(){
    long long int t,i;
    Pos1 t,f;
    cin>>t>>t.x>>t.y>>f.x>>f.y;
    char a[t];
    for(long long int i=0;i<t;i++)
        cin>>a[i];
    if(t.x>f.x&&t.y>f.y)
        for(i=0;i<t;i++)
            if(a[t]=='N'||a[t]=='E')
                a[t]=0;
    else if(t.x<f.x&&t.y<f.y)
        for(i=0;i<t;i++)
            if(a[t]=='S'||a[t]=='W')
                a[t]=0;
    else if(i.x<f.x&&i.y>f.y)
        for(i=0;i<t;i++)
            if(a[t]=='W'||a[t]=='N')
                a[t]=0;
    else if(i.x>f.x&&i.y<f.y)
        for(i=0;i<t;i++)
            if(a[t]=='E'||a[t]=='N')
                a[t]=0;
    for(i=0;i<n;i++){
        if(a[t]=='S')
            i.y-=1;
        else if(a[t]=='N')
            i.y+=1;
        else if(a[t]=='E')
            i.x+=1;
        else if(a[t]=='W')
            i.x-=1;
        if(i.x==f.x&&i.y==f.y){
            cout<<i+1;return 0;
        }
    }
    cout<<"-1";
return 0;}
