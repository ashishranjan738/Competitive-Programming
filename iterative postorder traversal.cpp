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
void ipostOrder(node* root){
    if(root){
        stack<node*> s1;
        stack<node*> s2;
        s1.push(root);
        while(!s1.empty()){
            node* temp=s1.top();
            s1.pop();
            s2.push(temp);
            if(temp->left)s1.push(temp->left);
            if(temp->right)s1.push(temp->right);
        }
        while(!s2.empty()){
            node* temp=s2.top();
            s2.pop();
            cout<<temp->data<<" ";
        }
    }
}
void postOrder(node* root){
    if(root){
        if(root->left)postOrder(root->left);
        if(root->right)postOrder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    node* root=new node(10);
    root->right=new node(20);
    root->left=new node(13);
    root->left->right=new node(14);
    root->right->left=new node(15);
    postOrder(root);
    cout<<endl;
    ipostOrder(root);
    return 0;
}
