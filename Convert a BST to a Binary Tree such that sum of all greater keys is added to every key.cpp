#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int temp){
        left=right=NULL;
        data=temp;
    }
};
void sum1(node* root,int *sum){
    if(root){
        if(root->right)sum1(root->right,sum);
        root->data+=*sum;
        *sum=root->data;
        if(root->left)sum1(root->left,sum);
    }
}
void inOrder(node* root){
    if(root){
        if(root->left)inOrder(root->left);
        cout<<root->data<<" ";
        if(root->left)inOrder(root->right);
    }
}
int main(){
    node* root=new node(5);
    root->right=new node(13);
    root->left=new node(2);
    int sum=0;
    sum1(root,&sum);
    inOrder(root);
    return 0;
}
