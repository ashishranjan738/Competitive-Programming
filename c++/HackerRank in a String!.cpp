#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    stack<int> st;
    string temp="hackerrank";
    for(int i=temp.length()-1;i>=0;i--)
        st.push(temp[i]);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(st.top()==s[i]){
            st.pop();
        }
    }
    st.empty()?cout<<"YES\n":cout<<"NO\n";
}
return 0;}
