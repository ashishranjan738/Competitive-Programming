#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
    int number;
    TrieNode(){
        for(int i=0;i<26;i++)
            child[i]=NULL;
        isEnd=false;
        number=0;
    }
};
void insertNode(TrieNode** root,string &s){
    if(*root){
        TrieNode* pCrawl=*root;
        for(int i=0;i<s.length();i++){
            if(!pCrawl->child[s[i]-'a'])
                pCrawl->child[s[i]-'a']=new TrieNode();
            pCrawl=pCrawl->child[s[i]-'a'];
            pCrawl->number++;
        }
        pCrawl->isEnd=true;
    }
    else{
        *root=new TrieNode();
        insertNode(root,s);
    }
}
int solve(TrieNode* root,string &s){
    if(root){
        for(int i=0;i<s.length();i++){
            if(!root->child[s[i]-'a'])
                return 0;
            root=root->child[s[i]-'a'];
        }
        return root->number;
    }
    else return 0;
}
int main(){
    int t;
    cin>>t;
    TrieNode* root=NULL;
    while(t--){
        string s;
        cin>>s;
        if(s=="add"){
            string temp;
            cin>>temp;
            insertNode(&root,temp);
        }
        else{
            string temp;
            cin>>temp;
            cout<<solve(root,temp)<<endl;
        }
    }
    cout<<root->child[0]->isEnd;
    return 0;
}
