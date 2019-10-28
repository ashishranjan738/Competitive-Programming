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
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
    }else *root=getNode(data);
}
void deleteNext(node* root,node** head){
    node* temp=root->next;
    makeList(&(*head),temp->data);
    root->next=temp->next;
    delete(temp);
}
node* doAlternate(node** root){
    node* ptr=*root;
    node* head=NULL;
   while(ptr && ptr->next){
        deleteNext(ptr,&head);
        ptr=ptr->next;
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
node* head1=NULL;
for(int i=0;i<10;i++){
 makeList(&head1,i);
}
print(head1);
node* head2=doAlternate(&head1);
cout<<endl;
print(head1);
cout<<endl;
print(head2);

return 0;}
