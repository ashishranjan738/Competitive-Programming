#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(st.empty())
            st.push(s[i]);
        else if(st.top()==s[i])
            st.pop();
        else{
            st.push(s[i]);
        }
    }
    s.clear();
    if(st.empty()){cout<<"Empty String\n";return 0;}
    while(!st.empty()){
        s.push_back(st.top());
        st.pop();
    }
    for(int i=s.length()-1;i>=0;i--)cout<<s[i];
return 0;}
