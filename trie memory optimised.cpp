#include<bits/stdc++.h>
using namespace std;
#define Free(p) free(p);p=NULL;
struct TrieNode{
    map<char,TrieNode*> m;
    int isEnd;
    TrieNode(){
        isEnd=0;
    }
};
void insertWord(TrieNode** root,const string &s){
    if(*root){
        TrieNode* temp=*root;
        for(int i=0;i<s.length();i++){
            if(!temp->m[s[i]])
                temp->m[s[i]]=new TrieNode();
            temp=temp->m[s[i]];
        }
        temp->isEnd++;
    }
    else{
        *root=new TrieNode();
        insertWord(root,s);
    }
}
bool findWord(TrieNode* root,const string &s){
    if(!root)
        return false;
    else{
        for(int i=0;i<s.length();i++){
            if(!root->m[s[i]])
                return false;
            else
                root=root->m[s[i]];
        }
        return (root->isEnd)?true:false;
    }
}
bool haveChild(TrieNode* root){
    if(!root)
        return false;
    else{
        for(auto it=root->m.begin();it!=root->m.end();it++){
            if((*it).second)
                return false;
        }
        return true;
    }
}
bool isLeafNode(TrieNode* root){
    if(!root)
        return false;
    else return root->isEnd;
}
bool deleteWordH(TrieNode* root,const string &s,int len,int level){
    if(root){
        if(level==len){
            if(root->isEnd)
                root->isEnd=0;
            if(haveChild(root))
                return false;
            else return true;
        }
        else{
            if(deleteWordH(root->m[s[level]],s,len,level+1)){
                Free(root->m[s[level]]);
                return !isLeafNode(root) && !haveChild(root);
            }
        }
    }
    return false;
}
void deleteWord(TrieNode* root,const string &s){
    int len=s.length();
    if(len>0)
        deleteWordH(root,s,len,0);
}
int main(){
    TrieNode* root=NULL;
    string s;
    while(1){
        int val;
        cout<<"1.Insert\n2.Check\n";
        cin>>val;
        switch(val){
            case 1: cin>>s;
                    insertWord(&root,s);
                    break;
            case 2: cin>>s;
                    cout<<findWord(root,s);
                    break;
            case 3: cin>>s;
                    deleteWord(root,s);
                    break;
            default:cin>>s;
                    if(s[0]=='x')
                    return 0;
        }
    }
    return 0;
}
