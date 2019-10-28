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
void insertNode(node* root1,node* root2){
    node* temp=root1->next;
    root2->next=temp;
    root1->next=root2;
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
void alternateInsert(node* root1,node* root2){
    while(root1&&root2){
        node* temp=root1->next;
        node* temp2=root2->next;
        insertNode(root1,root2);
        root1=temp;
        root2=temp2;
        if(!root1->next){
            root1->next=root2;
            break;
        }
    }

}
int main(){
node* head1=NULL;
node* head2=NULL;
for(int i=0;i<10;i++)
    makeList(&head1,i);
for(int i=10;i<25;i++)
    makeList(&head2,i);
alternateInsert(head1,head2);
print(head1);


return 0;}
