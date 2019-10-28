#include<bits/stdc++.h>
using namespace std;
void mergeSorted(vector<int> &A,vector<int> &B){
    vector<int>::iterator it1, it2;
    it1=A.begin();it2=B.begin();
    while(it2!=B.end()){
        while(*it2>*it1&&it1!=A.end())
            it1++;
        if(it1==A.begin()){
            A.insert(A.begin(),*it2);it1++;}
        else{A.insert(it1,*it2);it2++;}
        it1=A.begin();
    }
}
int main(){
int s1,s2;
cin>>s1>>s2;
vector<int> A(s1),B(s2);
for(int i=0;i<s1;i++)
    cin>>A[i];
for(int i=0;i<s2;i++)
    cin>>B[i];
mergeSorted(A,B);
cout<<endl;
for(int i=0;i<A.size();i++)
    cout<<A[i]<<" ";
return 0;}
