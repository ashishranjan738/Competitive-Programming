#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    map<char,TrieNode*> m;
    bool isEnd;
    bool isTaken;
    TrieNode(){
        isEnd=false;
        isTaken=false;
    }
};
void solve(TrieNode** root,string &s,bool &flag){
    if(*root){
        TrieNode* pCrawl=*root;
        for(int i=0;i<s.length();i++){
            if(!pCrawl->m[s[i]])
                pCrawl->m[s[i]]=new TrieNode();
            pCrawl->isTaken=true;
            pCrawl=pCrawl->m[s[i]];
            if(pCrawl->isEnd){
                cout<<"BAD SET \n"<<s<<endl;
                flag=0;
                return;
            }
        }
        if(pCrawl->isTaken){
            cout<<"BAD SET \n"<<s<<endl;
            flag=0;
            return;
        }
        pCrawl->isEnd=true;
    }
    else{
        *root=new TrieNode();
        solve(root,s,flag);
    }
}
int main(){
    int t;
    cin>>t;
    bool flag=1;
    TrieNode* root=NULL;
    while(t--){
        string s;
        cin>>s;
        solve(&root,s,flag);
        if(!flag)return 0;
    }
    if(flag)cout<<"Good SET\n";
    return 0;
}
