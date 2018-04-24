#include<bits/stdc++.h>
#include<stack>
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
void swapKelements(node** root,int k){
    node* ptr=*root;
    stack<int> a;
    if(k==0)
        return;
    while(ptr&&ptr->next){
        node* temp=ptr;
        for(int i=0;temp&&i<k;i++){
            //cout<<"pareshan";
            a.push(temp->data);
            temp=temp->next;
        }
        //cout<<"Hello";
        while(!a.empty()){
            ptr->data=a.top();
            a.pop();
            ptr=ptr->next;
        }
        //ptr=ptr->next;
    }
}
int main(){
node* root=NULL;
for(int i=1;i<=8;i++)
    makeList(&root,i);
print(root);
cout<<endl;
swapKelements(&root,0);
print(root);
return 0;}
