#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* right,*left;
    node(int temp){
        data=temp;
        right=left=NULL;
    }
};
void createBst(node** root,int arr[],int l,int r){
    if(l>r)
        return;
    int mid=l+(r-l)/2;
    *root=new node(arr[mid]);
    createBst(&(*root)->left,arr,l,mid-1);
    createBst(&(*root)->right,arr,mid+1,r);
}
void inOrder(node* root){
    if(root){
        if(root->left)inOrder(root->left);
        cout<<root->data<<" ";
        if(root->right)inOrder(root->right);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* root=NULL;
    createBst(&root,arr,0,n-1);
    inOrder(root);
    return 0;
}
