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
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
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
void rotateList(node** root,int k){
    if(k==0)
        return;
    node* ptr=*root;
    for(int i=0;ptr&&i<k-1;i++){
        ptr=ptr->next;
    }
    node* temp=*root;
    *root=ptr->next;
    node* ptr2=ptr->next;
    ptr->next=NULL;
    while(ptr2->next)
        ptr2=ptr2->next;
    ptr2->next=temp;
}
int main(){
node* root=NULL;
for(int i=0;i<10;i++){
    makeList(&root,i);
}
cout<<"List :\n";
print(root);
cout<<endl;
rotateList(&root,4);
print(root);
return 0;}
