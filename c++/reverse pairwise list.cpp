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
void createList(node** root,int data){
    if(*root){
        node* ptr=*root;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
    }
    else *root=getNode(data);
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
void swapNumber(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swapPairwise(node** root){
    if(*root){
        if(!(*root)->next)
            return;
        node* ptr=*root;
        while(ptr&&ptr->next){
            swapNumber(&ptr->data,&ptr->next->data);
            ptr=ptr->next->next;
        }
    }else return;
}
int main(){
node* head=NULL;
for(int i=0;i<10;i++)
    createList(&head,i);
print(head);
swapPairwise(&head);
cout<<endl;
print(head);
return 0;}
