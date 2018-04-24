#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int t){
        data=t;
        left=right=NULL;
    }
};
void modifyTreeUtil(node* root,stack<node*> &s){
    if(!root)return;
    if(root->right)modifyTreeUtil(root->right,s);
    if(root->left)modifyTreeUtil(root->left,s);
    root->right=root->left=NULL;
    s.push(root);
}
node* modifyTree(node* root){
    if(!root)
        return NULL;
    stack<node*> s;
    modifyTreeUtil(root,s);
    node* nroot=s.top(),*ptr=s.top();
    s.pop();
    while(!s.empty()){
        ptr->right=s.top();
        s.pop();
        ptr=ptr->right;
    }
    return nroot;
}
void printList(node* root){
    for(;root;root=root->right)
        cout<<root->data<<" ";
}
void levelOrder(node* root){
    if(!root)return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize=q.size();
        while(levelSize--){
            node* temp=q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
}
int main(){
    node* root=new node(1);
    root->right=new node(5);
    root->right->right=new node(6);
    root->left=new node(2);
    root->left->right=new node(4);
    root->left->left=new node(3);
    //levelOrder(root);
    root=modifyTree(root);
    printList(root);
    return 0;
}
