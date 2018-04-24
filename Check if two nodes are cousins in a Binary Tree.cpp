#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
};
node* getNode(int data){
    node* ret=new node;
    ret->right=ret->left=NULL;
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
bool isSibling(node* root,node* a,node* b){
    return((root->left->data==a->data&&root->right->data==b->data)||(root->left->data==b->data&&root->right->data==a->data)||isSibling(root->left,a,b)||isSibling(root->right,a,b));
}
int level(node* root,node* ptr,int lev){
    if(!root) return 0;
    if(root->data==ptr->data) return lev;
    else{
        int l=level(root->left,ptr,lev+1);
        if(l!=0)return l;
    }
    return level(root->right,ptr,lev+1);
}
bool isCousinFinder(node* root,node* a,node* b){
    return (level(root,a,1)==level(root,b,1)&&isSibling(root,a,b));
}
node* findNode(node* root,int key){
    if(!root)
        return NULL;
    if(key==root->data) return root;
    else if(key<root->data) return findNode(root->left,key);
    else return findNode(root->right,key);
}
bool isCousin(node* root,int a,int b){
    return isCousinFinder(root,findNode(root,a),findNode(root,b));
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
int a,b;
cin>>a>>b;
cout<<isCousin(root,a,b);
return 0;}
