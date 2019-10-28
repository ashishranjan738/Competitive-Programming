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
void postOrderR(node* root){
    if(!root) return;
    postOrderR(root->left);
    postOrderR(root->right);
    cout<<root->data<<" ";
}
void postOrderWO(node* root){

}
int main(){
node* root=NULL;
for(int i=0;i<6;i++){
    int temp;cin>>temp;
    createBST(&root,temp);
}
inOrderR(root);
cout<<endl;
inOrderWO(root);
return 0;}
