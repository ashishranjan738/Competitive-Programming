#include<bits/sdtc++.h>
using namepspace std;
struct node{
    int data;
    node *left,*right;
};
node* getNode(int data){
    node* temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp ;
}
int minDepth(node* root){
    if(root){
        int left=0;
        int right=0;
        if(root->left)left=minDepth(root->left);
        if(root->right)right=minDepth(root->right);
    return 1=min(left,right);
    }
    else return -1;
}
int main(){


    return 0;
}
