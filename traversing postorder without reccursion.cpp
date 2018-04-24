#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
};
node* getNode(int data){
    node* ret=new node;
    ret->data=data;
    ret->left=NULL;
    ret->right=NULL;
return ret;
}
void createBST(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createBST(&(*root)->left,data);
        else createBST(&(*root)->right,data);
    }
    else *root=getNode(data);
}
void preOrderR(node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preOrderR(root->left);
    preOrderR(root->right);
}
void preOrderWO(node* root){
    if(!root) return;
    stack<node*> S;
    S.push(root);
    while(!S.empty()){
        node* temp=S.top();
        cout<<temp->data<<" ";
        S.pop();
        if(temp->right)S.push(temp->right);
        if(temp->left)S.push(temp->left);
    }
}
int main(){
node* root=NULL;
for(int i=0;i<6;i++){
    int temp;cin>>temp;
    createBST(&root,temp);
}
preOrderR(root);
cout<<endl;
preOrderWO(root);
return 0;}
