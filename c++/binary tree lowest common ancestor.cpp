#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int a){
        left=right=NULL;
        data=a;
    }
};
void createBst(node** root,int data){
    if(*root){
        if((*root)->data<data)
            createBst(&(*root)->left,data);
        else createBst(&(*root)->right,data);
    }
    else *root=new node(data);
}
void levelOrder(node* root){
    if(root){
        queue<node*> q;
        q.push(root);
        while(1){
            if(q.empty())
                break;
            int NodeCount=q.size();
            while(NodeCount){
                node* temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                NodeCount--;
            }
            cout<<endl;
        }
    }
}
int main(){
    node* root=new node(10);
    createBst(&root,3);
    createBst(&root,6);
    createBst(&root,11);
    createBst(&root,13);
    cout<<endl;
    levelOrder(root);
    return 0;
}
