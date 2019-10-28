#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node* getNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void createTree(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createTree(&(*root)->left,data);
        else createTree(&(*root)->right,data);
    }
    else *root=getNode(data);
}
int levelOrder(node* root){
    if(!root)
        return 0;
    int height=0;
    queue<node*> q;
    q.push(root);
    while(1){
        int nodeCount=q.size();
        if(!nodeCount)
            return height;
        height++;
        while(nodeCount>0){
            node* temp=q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            nodeCount--;
        }
    }
}
int minDepth(node* root){
    if(root){
        if(root->left&&!root->right)
            return 1+minDepth(root->left);
        else if(!root->left&&root->right)
            return 1+minDepth(root->right);
        else
            return 1+min(minDepth(root->left),minDepth(root->right));
    }
    else return 0;
}
int main(){
    node* root=NULL;
    createTree(&root,10);
    createTree(&root,11);
    createTree(&root,11);
    cout<<levelOrder(root);
    cout<<endl<<minDepth(root);
    return 0;
}

