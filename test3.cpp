#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &i:v)
        cin>>i;
    int index=find(v.begin(),v.end(),3)-v.begin();
    cout<<index;
    return 0;
}