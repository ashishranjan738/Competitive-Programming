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
    }
    else *root=getNode(data);
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
node* findIntersect(node* root1,node* root2){
    node* temp=NULL;
    while(root1&&root2){
        if(root1->data==root2->data){
            makeList(&temp,root1->data);
            root1=root1->next;
            root2=root2->next;
        }
        else if(root1->data<root2->data)
            root1=root1->next;
        else root2=root2->next;
    }
return temp;
}
int main(){
node* head1=NULL;
node* head2=NULL;
for(int i=0;i<10;i++)
    makeList(&head1,i);
for(int i=0;i<5;i++){
    int j;
    cin>>j;
    makeList(&head2,j);
}
print(head1);
cout<<endl;
print(head2);
cout<<endl;
node* head3=findIntersect(head1,head2);
print(head3);
return 0;}
