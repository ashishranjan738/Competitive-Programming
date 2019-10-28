#include<bits/stdc++.h>
using namespace std;
void simplify(string &s){
    queue<char> q;
    stack<char> st;
    st.push('+');
    for(int i=0;i<s.length();i++)
        q.push(s[i]);
    s.clear();
    while(!q.empty()){
        if(q.front()==')'){
            q.pop();
            if(st.size()>1)st.pop();
        }
        else if(q.front()=='-'){
            q.pop();
            if(q.front()=='('){
                if(st.top()=='-')st.push('+');
                else st.push('-');
                //q.pop();
            }
            else{
                if(st.top()=='-'){
                        if(s.length())s.push_back('+');}
                else s.push_back('-');
            }
        }
        else if(q.front()=='('){
            q.pop();
            if(q.front()==')')
                continue;
            if(q.front()!='-'&&q.front()!='+'){
                if(st.top()=='-')s.push_back(st.top());
                else if(s.length())s.push_back(st.top());
            }
//            if(q.front()=='-'&&st.top()=='-'&&q.front()){
//                if(s.length())s.push_back('+');
//                q.pop();
//            }
//            else if(st.top()=='-')
//                s.push_back('-');
//            else if(s.length()&&){
//               // cout<<"hello"<<endl;
//                //cout<<s.length()<<endl<<s<<endl;
//                s.push_back('+');
//            }
        }
        else if(q.front()=='+'){
            q.pop();
            if(st.top()=='-' && s.length() && q.front()!='(' && q.front()!=')')s.push_back('-');
            else if(s.length() && q.front()!='(' && q.front()!=')')s.push_back('+');
        }
        else{
            s.push_back(q.front());
            q.pop();
        }
    }
}
bool solve(string &s1,string s2){
    simplify(s1);
    simplify(s2);
   // cout<<s1<<" "<<s2<<endl;
    if(!s1.compare(s2))return true;
    map<char,int> m1;
    map<char,int> m2;
    int i=0;
    string tmp;
    while(i<s1.length()){
        if(i==0&&s1[i]!='+'&&s1[i]!='-'){
            tmp.push_back('+');
            tmp.push_back(s1[i++]);
            if(tmp[0]=='+')m1[tmp[1]]++;
            else m1[tmp[1]]--;
        }
        else{
            tmp.push_back(s1[i++]);
            tmp.push_back(s1[i++]);
            if(tmp[0]=='+')m1[tmp[1]]++;
            else m1[tmp[1]]--;
        }
    //    cout<<tmp<<endl;
        tmp.clear();
    }
//    for(auto it=m1.begin();it!=m1.end();it++){
//        cout<<(*it).first<<" "<<(*it).second<<endl;
//    }
    i=0;
    tmp.clear();
    while(i<s2.length()){
        if(i==0&&s2[i]!='+'&&s2[i]!='-'){
            tmp.push_back('+');
            tmp.push_back(s2[i++]);
            if(tmp[0]=='+')m2[tmp[1]]++;
            else m2[tmp[1]]--;
        }
        else{
            tmp.push_back(s2[i++]);
            tmp.push_back(s2[i++]);
            if(tmp[0]=='+')m2[tmp[1]]++;
            else m2[tmp[1]]--;
        }
        tmp.clear();
    }
    //if(m1.size()!=m2.size())return false;
    for(auto it=m1.begin();it!=m1.end();it++){
        if(m2[(*it).first]!=(*it).second)return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        solve(s1,s2)?cout<<"YES\n":cout<<"NO\n";
    }
//    string s;
//    cin>>s;
//    solve(s);
    //cout<<s;
    return 0;
}
