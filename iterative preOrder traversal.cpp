#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int temp){
        data=temp;
        left=right=NULL;
    }
};
void preOrder(node* root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void ipreOrder(node* root){
    if(root){
        stack<node*> s;
        s.push(root);
        while(!s.empty()){
            node* temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            if(temp->right)s.push(temp->right);
            if(temp->left)s.push(temp->left);
        }
    }
}
int main(){
    node* root=new node(10);
    root->right=new node(12);
    root->left=new node(13);
    root->right->left=new node(17);
    root->left->right=new node(16);
    preOrder(root);
    cout<<endl;
    ipreOrder(root);
    return 0;
}
