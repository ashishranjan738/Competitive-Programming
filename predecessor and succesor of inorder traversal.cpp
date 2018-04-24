#include<bits/stdc++.h>
#include<stack>
using namespace std;
struct node{
    int data;
    node* left,*right;
};
node* getNode(int data){
    node* ret=new node;
    ret->left=NULL;
    ret->right=NULL;
    ret->data=data;
return ret;
}
void createNode(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createNode(&(*root)->left,data);
        else createNode(&(*root)->right,data);
    }
    else *root=getNode(data);
}
void inOrder(node* root){
    if(!root) return;
    stack<node*> s;
    node* temp=root;
    while(temp||!s.empty()){
        if(temp){
            s.push(temp);
            temp=temp->left;
        }
        else{
            cout<<s.top()->data<<" ";
            temp=s.top();
            s.pop();
            temp=temp->right;
        }
    }
}
node* findMin(node* root){
    if(root){
        while(root->left){
            root=root->left;
        }
        return root;
    }
}
node* succssor(node* root,int key){
    node* temp=root;
    while(temp->data!=key){
        if(key<temp->data)
            temp=temp->left;
        else temp=temp->right;
    }
    node* succ;
    if(temp->right){
        succ=findMin(root->right);
    }
    else{
        while(root->right!=temp){
            succ=root;
            if(key<root->data)
                root=root->left;
            else root=root->right;
        }
        return succ;
    }
}
int main(){
node* root=NULL;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int temp;cin>>temp;
    createNode(&root,temp);
}
inOrder(root);
cout<<endl;
int key;
cin>>key;
cout<<(succssor(root,key))->data;
return 0;}
