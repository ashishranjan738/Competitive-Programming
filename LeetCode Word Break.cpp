#include <bits/stdc++.h>
using namespace std;
bool solution(string s,vector<string> v){
    vector<bool> valid(s.length(),0);
    for(int i=0;i<s.length();i++){
        string word=s.substr(0,i+1);
        if(find(v.begin(),v.end(),word)!=v.end()){
            valid[i]=true;
            //break;
        }
        else{
            for(int j=0;j<i;j++){
                if(valid[j] && (find(v.begin(),v.end(),s.substr(j+1,i-j))!=v.end())){
                    valid[i]=true;
                    break;
                }
            }
        }
    }
    return valid[s.length()-1];
}
int main(){
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string> v(n);
    for(string &t:v)cin>>t;
    cout<<solution(s,v);


}