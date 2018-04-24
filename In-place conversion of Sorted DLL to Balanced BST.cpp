#include<bits/stdc++.h>
using namespace std;
struct node{
    node* prev,*next;
    int data;
    node(int temp){
        data=temp;
        prev=next=NULL;
    }
};
void createList(node** root,int data){
    if(*root){
        node* prev=*root;
        node* ptr=*root;
        for(;ptr->next;ptr=ptr->next);
        ptr->next=new node(data);
        ptr->next->prev=ptr;
    }
    else *root=new node(data);
}
void printList(node* root){
    for(;root->next;root=root->next)
        cout<<root->data<<" ";
    cout<<root->data<<endl;
    for(;root->prev;root=root->prev)
        cout<<root->data<<" ";
    cout<<root->data<<" ";
}
int countNodes(node* root){
    int it=0;
    for(;root;root=root->next)
        it++;
    return it;
}
node* convertSdll2BstUtil(node** root,int n){
    if(n<=0)
        return NULL;
    node* left=convertSdll2BstUtil(root,n/2);
    node* ptr=*root;
    ptr->prev=left;
    *root=(*root)->next;
    ptr->next=convertSdll2BstUtil(root,n-n/2-1);
    return ptr;
}
node* convertSdll2bst(node* root){
    int n=countNodes(root);
    //cout<<root;
    //printList(root);
    return convertSdll2BstUtil(&root,n);
}

void levelOrder(node* root){
    if(root){
        queue<node*>  q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            while(levelSize--){
                node* temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->prev)q.push(temp->prev);
                if(temp->next)q.push(temp->next);
            }
            cout<<endl;
        }
    }
}
int main(){
    node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        createList(&root,temp);
    }
    //printList(root);

    root=convertSdll2bst(root);
    levelOrder(root);
    return 0;
}
