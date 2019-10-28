#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node* getNode(int data){
    node* ret=new node;
    ret->left=ret->right=NULL;
    ret->data=data;
return ret;
}
void createTree(node** root,int data){
    if(*root){
        if(data<(*root)->data)createTree(&(*root)->left,data);
        else createTree(&(*root)->right,data);
    }
    else *root=getNode(data);
}
int calHeight(node* root){
    if(!root)return -1;
    return max(calHeight(root->left),calHeight(root->right))+1;
}
void inOrder(node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
void levelOrder(node* root,int h){
    if(h==0)
        cout<<root->data<<" ";
    else{
        if(root->left)levelOrder(root->left,h-1);
        if(root->right)levelOrder(root->right,h-1);
    }
}
void inOrderD(node* root){
    if(root){
        inOrderD(root->right);
        cout<<root->data<<" ";
        inOrderD(root->left);
    }
}
void modifyBSTInOrder(node* root,int* sum){
    if(root){
        modifyBSTInOrder(root->left,sum);
        *sum=*sum+root->data;
        root->data=*sum;
        modifyBSTInOrder(root->right,sum);
    }
}
void modifyBSTInOrderD(node* root,int *sum){
    if(root){
        modifyBSTInOrderD(root->right,sum);
        *sum=*sum+root->data;
        root->data=*sum;
        modifyBSTInOrderD(root->left,sum);
    }
}
void modifyBST(node* root){
    int sum=0;
    modifyBSTInOrderD(root,&sum);
}
int main(){
    node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        createTree(&root,temp);
    }
    for(int i=0;i<=calHeight(root);i++){
        levelOrder(root,i);
        cout<<endl;
    }
    cout<<endl;
    modifyBST(root);
    for(int i=0;i<=calHeight(root);i++){
        levelOrder(root,i);
        cout<<endl;
    }
return 0;
}
