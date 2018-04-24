#include<bits/stdc++.h>
using namespace std;
struct node{
    node* next;
    int data;
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
node* sortedInsert(node** root,int data){
    if(*root){
        if(data<(*root)->data){
            node* temp=*root;
            *root=getNode(data);
            (*root)->next=temp;
        }
        else{
            node* ptr=*root;
            while(ptr->next){
                if(data<ptr->next->data){
                    break;
                }
                ptr=ptr->next;
            }
            node* temp=ptr->next;
            ptr->next=getNode(data);
            ptr->next->next=temp;
        }
    }
    else *root=getNode(data);
}
node* insertionSort(node* root){
    node* head=NULL;
    while(root){
        sortedInsert(&head,root->data);
        root=root->next;
    }
    return head;
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
int main(){
node* head=NULL;
makeList(&head,8);
makeList(&head,9);
makeList(&head,2);
makeList(&head,1);
makeList(&head,6);
makeList(&head,7);
makeList(&head,3);
makeList(&head,4);
print(head);
cout<<"test\n";
node* head2=insertionSort(head);
print(head2);
return 0;}
