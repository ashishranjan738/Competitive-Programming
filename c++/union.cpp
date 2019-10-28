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
    ret->prev=NULL;
    ret->next=NULL;
return ret;
}
void makeList(Nod)
