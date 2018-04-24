#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* getNode(int data){
    Node* ret=new Node;
    ret->data=data;
    ret->next=NULL;
    ret->prev=NULL;
return ret;
}
void reverseList(Node** head){
    Node* ptr=*head;
    while((*head)->next){
        ptr=(*head)->next;
        Node* temp=(*head)->next;
        (*head)->next=(*head)->prev;
        (*head)->prev=temp;
        *head=ptr;
    }
    Node* temp=(*head)->next;
    (*head)->next=(*head)->prev;
    (*head)->prev=temp;
}
void makeList(Node** root,int data){
    if(*root){
        Node* ptr=*root;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
        ptr->next->prev=ptr;
    }
    else *root=getNode(data);
}
void printList(Node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
void printListRev(Node* root){
    while(root->next)
        root=root->next;
    while(root){
        cout<<root->data<<" ";
        root=root->prev;
    }
}
void sortedInsert(Node** root,int data){
    if(*root){
        if(data<(*root)->data){
            Node* temp=getNode(data);
            (*root)->prev=temp;
            temp->next=*root;
            *root=temp;
        }
        else{
            Node* ptr=*root;
            while(ptr->next&&data>ptr->data){
                ptr=ptr->next;
            }
            if(!ptr->next){
                ptr->next=getNode(data);
                ptr->next->prev=ptr;
            }
            else{
                Node* temp=getNode(data);
                temp->next=ptr;
                temp->prev=ptr->prev;
                ptr->prev->next=temp;
                ptr->prev=temp;
            }
        }
    }
    else *root=getNode(data);
}
int main(){
Node* head=NULL;
for(int i=0;i<10;i++)
    makeList(&head,i);
for(int i=11;i<20;i++)
    makeList(&head,i);
sortedInsert(&head,10);
sortedInsert(&head,-1);
sortedInsert(&head,66);
printList(head);
cout<<endl;
reverseList(&head);
printList(head);
cout<<endl;
printListRev(head);
return 0;}
