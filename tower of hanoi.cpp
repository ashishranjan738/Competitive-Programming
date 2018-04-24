#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char from,char to,char aux){
    if(n==1){
        cout<<"moved "<<n<<" discs  from "<<from<<" to "<<to<<endl;
        return;
    }
    TOH(n-1,from,aux,to);
    cout<<"moved "<<n<<" discs  from "<<from<<" to "<<to<<"recc"<<endl;
    TOH(n-1,aux,to,from);
}
int main(){
int n;
cin>>n;
TOH(n,'A','B','C');
return 0;}
