#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int temp){
        left=right=NULL;
        data=temp;
    }
};
void inOrder(node* root){
    if(root){
        if(root->left)inOrder(root->left);
        cout<<root->data<<" ";
        if(root->right)inOrder(root->right);
    }
}
void iinOrder(node* root){
    if(root){
        stack<node*> s1;
        //s1.push(root);
        while(1){
            if(root!=NULL){
                s1.push(root);
                root=root->left;
            }
            else{
                if(s1.empty())
                    break;
                root=s1.top();
                s1.pop();
                cout<<root->data<<" ";
                root=root->right;
            }
        }
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(12);
    root->right=new node(15);
    root->right->left=new node(13);
    root->left->right=new node(14);
    inOrder(root);
    cout<<endl;
    iinOrder(root);
    return 0;
}

