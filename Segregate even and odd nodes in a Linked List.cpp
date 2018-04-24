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
void makeList(node* root){
    if(*root){
        node* ptr=*root;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
    }
    else *root=getNode(data);
}
