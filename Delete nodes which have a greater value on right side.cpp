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
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
    }
    else *root=getNode(data);
}
void reverseList(node** root){
    node* prev=NULL;
    node* current=*root;
    node* next;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *root=prev;
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
void deleteNode(node* root){
    node*temp=root->next;
    root->next=temp->next;
    delete(temp);
}
void deleteRight(node** root){
    if(*root){
        node* ptr=*root;
        while(ptr->next){
            if(ptr->next->data<ptr->data){
                deleteNode(ptr);
            }
            ptr=ptr->next;
        }
    }
}
int main(){
node* root=NULL;
for(int i=0;i<10;i++)
    makeList(&root,i);
print(root);
reverseList(&root);cout<<endl;
deleteRight(&root);
reverseList(&root);
cout<<endl;
print(root);
return 0;}
