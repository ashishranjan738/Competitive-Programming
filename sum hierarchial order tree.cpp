#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int a){
        data=a;
        left=right=NULL;
    }
};
int calHeirarchial(node** root){
    if(*root){
        (*root)->data+=calHeirarchial(&(*root)->left)+calHeirarchial(&(*root)->right);
        return (*root)->data;
    }
    else return 0;
}
void levelOrder(node* root){
    if(root){
        queue<node*> q;
        q.push(root);
        int NodeCount=q.size();
        while(1){
            NodeCount=q.size();
            if(!NodeCount)
                break;
            while(NodeCount>0){
                node* temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                NodeCount--;
            }
            cout<<endl;
        }
    }
}
int main(){
    node* root=new node(2);
    root->left=new node(4);
    root->right=new node(1);
    root->left->right=new node(9);
    root->left->right->left=new node(3);
    root->left->left=new node(6);
    root->right->right=new node(2);
    levelOrder(root);
    calHeirarchial(&root);
    levelOrder(root);
    return 0;
}
