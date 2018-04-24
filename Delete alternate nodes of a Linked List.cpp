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
void deleteNext(node* root){
    node* temp=root->next;
    root->next=temp->next;
    delete(temp);
}
void deleteAlternate(node** root){
    node* ptr=*root;
   while(ptr && ptr->next){
        deleteNext(ptr);
        ptr=ptr->next;
    }
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
cout<<endl;
deleteAlternate(&head1);
print(head1);

return 0;}
