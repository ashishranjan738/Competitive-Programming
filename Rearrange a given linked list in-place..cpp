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
return ret;}
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
void print(node *root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
node* findMid(node* root){
    node* fast=root;
    node* slow=root;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
void reverseList(node** root){
    if(*root){
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
    else return;
}
void insertNode(node* root1,node* root2){
    node* temp=root1->next;
    root2->next=temp;
    root1->next=root2;
}
void mergeList(node* root1,node* root2){
    while(root1&&root2){
        node* temp2=root2->next;
        node* temp1=root1->next;
        insertNode(root1,root2);
        root2=temp2;
        root1=temp1;
        if(!root1->next){
            root1->next=root2;
            break;
        }
    }
}
void inPlaceArrange(node** root){
    node* midhead=findMid(*root);
    node* ptr=midhead;
    midhead=midhead->next;
    ptr->next=NULL;
    reverseList(&midhead);
    mergeList(*root,midhead);
}
int main(){
node* head=NULL;
for(int i=0;i<5;i++)
    makeList(&head,i);
inPlaceArrange(&head);
print(head);
return 0;}
