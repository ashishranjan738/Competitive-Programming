#include<bits/stdc++.h>
#include<list>
using namespace std;
int main(){
list<int> a;
for(int i=0;i<10;i++)
    a.push_back(i);
for(int i=0;i<4;i++){
    int temp=a.front();
    a.pop_front();
    a.push_back(temp);
}
list<int>::iterator it;
for(it=a.begin();it!=a.end();it++)
    cout<<*it<<" ";
cout<<endl;
it=a.begin();
for(int i=0;i<2;i++)
    it++;
a.insert(it,99);
cout<<endl;
for(it=a.begin();it!=a.end();it++)
    cout<<*it<<" ";
return 0;}

