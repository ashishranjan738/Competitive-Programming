#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
struct Info{
    bool flag;
    int sz;
    int mn;
    int mx;
    int ans;
};
Info lBST(node* root){
    if(!root)
        return {true,0,INT_MIN,INT_MAX,0};
    else if(!root->left&&root->right)
        return {true,1,root->data,root->data,1};
    Info l=lBST(root->left);
    Info r=lBST(root->right);
    Info ret;
    ret.sz=1+l.sz+r.sz;
    if(l.flag&&r.flag&&root->data>l.mx&&root->data<r.mn){
        ret.mn=min(min(l.mn,r.mn),root->data);
        ret.mx=max(max(r.mx,l.mx),root->data);
        ret.ans=ret.sz;
        ret.flag=1;
        return ret;
    }
    ret.flag=0;
    ret.ans=max(l.sz,r.sz);
    return ret;
}
node* getNode(int data){
    node* ret=new node;
    ret->right=NULL;
    ret->left=NULL;
    ret->data=data;
return ret;
}
void createTree(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createTree(&(*root)->left,data);
        else createTree(&(*root)->right,data);
    }
    else *root=getNode(data);
}
void preOrder(node* root){
    if(!root)
         return ;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void preOrderW(node* root){
    if(!root)
        return;
    else{
        stack<node*> s;
        s.push(root);
        while(!s.empty()){
            node* temp=s.top();
            cout<<s.top()->data<<" ";
            s.pop();
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
    }
}
void inOrder(node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void inOrderW(node* root){
    if(!root)
        return;
    stack<node*> s;
    node* temp=root;
    while(!s.empty()||temp){
        if(temp){
            s.push(temp);
            temp=temp->left;
        }
        else{
            temp=s.top();
            cout<<s.top()->data<<" ";
            s.pop();
            temp=temp->right;
        }
    }
}
int main(){
node* root=NULL;
srand(time(0));
int n;
cin>>n;
for(int i=0;i<n;i++){
    createTree(&root,rand()%n);
}
cout<<lBST(root).ans;
return 0;}
