#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* getNode(int data){
    node* ret=new node;
    ret->left=NULL;
    ret->right=NULL;
    ret->data=data;
return ret;
}
void createTree(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createTree(&(*root)->left,data);
        else
            createTree(&(*root)->right,data);
    }
    else *root=getNode(data);
}
void inOrder(node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
node* findMin(node* root){
    if(!root)
        return NULL;
    else{
        while(root->left)
            root=root->left;
    }
    return root;
}
bool isExist(node* root,int data){
    if(root){
        if(root->data==data)
            return 1;
        else if(data<root->data)
            return isExist(root->left,data);
        else return isExist(root->right,data);
    }
    else
        return 0;
}
node* lcao(node* root,int v1,int v2){
    if(root==NULL)
        return NULL;
    else if(root->data>v2&&root->data>v1)
        return lcao(root->left,v1,v2);
    else if(root->data<v1&&root->data<v2)
        return lcao(root->right,v1,v2);
    return root;
}
node* lca(node*root,int v1,int v2){
    if(!root)
        return NULL;
    else if(root->data>v2)
        return lca(root->left,v1,v2);
    else if(root->data<v1)
        return lca(root->right,v1,v2);
    return root;
}
void findPreSuc(node* root,node*& pre,node*& suc,int key){
    if(!root)
        return;
    if(key==root->data){
        if(root->left){
            node* temp=root->left;
            while(temp->right)
                temp=temp->right;
            pre=temp;
        }
        if(root->right){
            node* temp=root->right;
            while(temp->left)
                temp=temp->left;
            suc=temp;
        }
        return;
    }
    if(key<root->data){
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else{
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }
}
bool isBst(node* root,int minval,int maxval){
    if(!root)
        return true;
    return (root->data>minval&&root->data<maxval&&isBst(root->left,minval,root->data)&&isBst(root->right,root->data,maxval));
}
int main(){
node* root=NULL;
createTree(&root,50);
createTree(&root,30);
createTree(&root,20);
createTree(&root,40);
createTree(&root,70);
createTree(&root,60);
createTree(&root,80);
node* pre=NULL;
node* suc=NULL;
cout<<"InOrder Traversal:\n";
inOrder(root);
cout<<endl;
findPreSuc(root,pre,suc,65);
cout<<pre->data<<" "<<suc->data;
cout<<endl<<isBst(root,INT_MIN,INT_MAX);
return 0;}
