#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *right,*left;
    node(int temp){
        data=temp;
        right=left=NULL;
    }
};
void findPointers(node* root,node** first,node** prev,node** last){
    if(root){
        findPointers(root->left,&(*first),&(*prev),&(*last));
        if(*prev&&(*prev)->data>root->data){
            if(!*first){
                *first=*prev;
                *last=root;
            }
            else{
                *last=root;
            }
        }
        *prev=root;
        findPointers(root->right,&(*first),&(*prev),&(*last));
    }
}
void inOrder(node* root){
    if(root){
        if(root->left)inOrder(root->left);
        cout<<root->data<<" ";
        if(root->left)inOrder(root->right);
    }
}
void correctBst(node** root){
    node* first=NULL,*prev=NULL,*last=NULL;
    findPointers(*root,&first,&prev,&last);
    if(first&&last){
        int temp=first->data;
        first->data=last->data;
        last->data=temp;
    }
    inOrder(*root);
}
int main(){
    node* root=new node(10);
    root->left=new node(5);
    root->left->right=new node(7);
    root->left->left=new node(4);
    root->right=new node(14);
    root->right->right=new node(17);
    root->right->left=new node(15);
    inOrder(root);
    cout<<endl;
    correctBst(&root);
    return 0;
}
