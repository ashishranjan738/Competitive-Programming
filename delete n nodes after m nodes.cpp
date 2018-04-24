#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
};
node* getNode(int data){
    node* ret=new node;
    ret->next=NULL;
    ret->data=data;
return ret;
}
void makeList(node** root,int data){
    if(*root){
        node* ptr=*root;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=getNode(data);
    }
    else *root=getNode(data);
}
void deleteNext(node* root){
    node* temp=root->next;
    root->next=temp->next;
    delete(temp);
}
void deleteNodes(node** root,int m,int n){
        if(m==0){
            for(int i=0;*root&&i<n;i++){
                node* temp=*root;
                *root=(*root)->next;
                delete(temp);
            }
        }
        else{
            node* ptr=*root;
            for(int i=0;ptr&&i<m-1;i++){
                ptr=ptr->next;
            }
            for(int i=0;ptr->next && i<n;i++){
                deleteNext(ptr);
            }
        }
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
int main(){
node* root=NULL;
for(int i=0;i<10;i++)
    makeList(&root,i);
deleteNodes(&root,3,3);
print(root);
return 0;}
