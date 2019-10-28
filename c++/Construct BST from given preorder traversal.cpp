#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int temp){
        left=right=NULL;
        data=temp;
    }
};
node* createBst(int arr[],int l,int r){
    if(l<=r){
        node* root=new node(arr[l]);
        int i;
        for(i=l+1;i<=r;i++){
            if(arr[i]>arr[l])
                break;
        }
        root->left=createBst(arr,l+1,i-1);
        root->right=createBst(arr,i,r);
        return root;
    }
    return NULL;
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
    node* root=createBst(arr,0,n-1);
    inOrder(root);
    return 0;
}
