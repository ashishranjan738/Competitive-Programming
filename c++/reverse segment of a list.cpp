#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
};
ListNode* getNode(int data){
    ListNode* ret=new ListNode;
    ret->next=NULL;
    ret->val=data;
    return ret;
}
void makeList(ListNode** root,int data){
    if(*root){
        ListNode* ptr=*root;
        while(ptr->next){
            ptr=ptr->next;
        }
        ptr->next=getNode(data);
    }
    else *root=getNode(data);
}
void print(ListNode *root){
    while(root){
      cout<<root->val<<" ";
      root=root->next;
    }
}
void reverseList(ListNode** startList,ListNode** endList){
    ListNode* current=*startList;
    ListNode* prev=*endList;
    ListNode* next;
    ListNode* last=*endList;
    while(current!=last){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *startList=prev;
}
int main(){
ListNode* root=NULL;
for(int i=1;i<=5;i++)
    makeList(&root,i);
ListNode* prev1=root;
ListNode* prev2=root;
ListNode* ptr=root;
for(int i=0;i<0;i++){
    prev1=ptr;
    ptr=ptr->next;
}
prev2=ptr;
for(int i=0;i<2;i++){
    prev2=ptr;
    ptr=ptr->next;
}
cout<<prev1->val<<" "<<prev2->val<<endl;
reverseList(&root,&prev2->next);
print(root);
return 0;}
