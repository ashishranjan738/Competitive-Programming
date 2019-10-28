#include<bits/stdc++.h>
using namespace std;
struct node{
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
int calheight(node* root){
    if(!root)return -1;
    else return max(calheight(root->left),calheight(root->right))+1;
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
node* findMin(node* root){
    if(!root)return NULL;
    if(!root->left)return root;
    else return findMin(root->left);
}
node* deleteNode(node* root,int key){
    if(root){
        if(key<root->data)root->left=deleteNode(root->left,key);
        else if(key>root->data)root->right=deleteNode(root->right,key);
        else{
            if(!root->left&&!root->right){
                delete(root);
                root=NULL;
            }
            else if(root->right&&root->left){
                root->data=findMin(root->right)->data;
                cout<<"the minimum is "<<root->data<<endl;
                root->right=deleteNode(root->right,root->data);
            }
            else{
                if(root->left){
                    node* temp=root;
                    root=root->left;
                    delete temp;
                }
                if(root->right){
                    node* temp=root;
                    root=root->right;
                    delete temp;
                }
            }
        }
        return root;
    }
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
    deleteNode(root,5);
    for(int i=0;i<=h;i++){
        levelOrder(root,i);
        cout<<endl;
    }
return 0;}
