#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node* left,*right;
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
void levelOrder(node* root,int h){
    if(root){
        if(!h)cout<<root->data<<" ";
        else{
            if(root->left)levelOrder(root->left,h-1);
            if(root->right)levelOrder(root->right,h-1);
        }
    }
}
int calheight(node* root){
    if(!root)return -1;
    else return max(calheight(root->left),calheight(root->right))+1;
}
node* fixTree(node* root,int mini,int maxi){
    if(!root)return NULL;
    root->left=fixTree(root->left,mini,maxi);
    root->right=fixTree(root->right,mini,maxi);
    if(root->data<mini){
        node* rcld=root->right;
        delete root;
        return rcld;
    }
    if(root->data>maxi){
        node* lcld=root->left;
        delete root;
        return lcld;
    }
return root;
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
int h=calheight(root);
for(int i=0;i<=h;i++){
    levelOrder(root,i);
    cout<<endl;
}
root=fixTree(root,3,7);
h=calheight(root);
for(int i=0;i<=h;i++){
    levelOrder(root,i);
    cout<<endl;
}
return 0;}
