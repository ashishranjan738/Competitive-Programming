#include<bits/stdc++.h>
#include <stdlib.h>
#include<algorithm>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int num=0;
        unsigned long long int l,r;
        cin>>l>>r;
        string s[18]={"0000000000000000000000000000000000000000000000000000000000000011","0000000000000000000000000000000000000000000000000000000000000111","0000000000000000000000000000000000000000000000000000000000011111","0000000000000000000000000000000000000000000000000000000001111111","0000000000000000000000000000000000000000000000000000011111111111","0000000000000000000000000000000000000000000000000001111111111111","0000000000000000000000000000000000000000000000011111111111111111","0000000000000000000000000000000000000000000001111111111111111111","0000000000000000000000000000000000000000011111111111111111111111","0000000000000000000000000000000000011111111111111111111111111111","0000000000000000000000000000000001111111111111111111111111111111","0000000000000000000000000001111111111111111111111111111111111111","0000000000000000000000011111111111111111111111111111111111111111","0000000000000000000001111111111111111111111111111111111111111111","0000000000000000011111111111111111111111111111111111111111111111","0000000000011111111111111111111111111111111111111111111111111111","0000011111111111111111111111111111111111111111111111111111111111","0001111111111111111111111111111111111111111111111111111111111111"};
        for(int i=0;i<18;i++){
            int temp=strtoull(s[i].c_str(),NULL,2);
            if(temp>r)
                break;
            if(temp<=r&&temp>=l){
                num++;
            }
        }
        for(int i=0;i<18;i++){
            while(next_permutation(s[i].begin(),s[i].end())){
            unsigned long long int temp=strtoull(s[i].c_str(),NULL,2);
//                cout<<temp<<endl;
            if(temp>r)
                break;
            if(temp<=r&&temp>=l){
                num++;
            }
            }
        }
        cout<<num<<"\n";
    }
    return 0;
}
