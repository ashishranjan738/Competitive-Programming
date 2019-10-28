#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    node(int temp){
        data=temp;
        next=NULL;
    }
};
struct nodet{
    int data;
    nodet *left,*right;
    nodet(int temp){
        data=temp;
        left=right=NULL;
    }
};
int countNodes(node* root){
    int it=0;
    for(;root;root=root->next){
        it++;
    }
    return it;
}
nodet* convertBstUtil(node* root,int n){
    if(!root||!n)
        return NULL;
    node* ptr=root;
    for(int i=0;i<n/2&&ptr;ptr=ptr->next)
        i++;
    nodet* temp=new nodet(ptr->data);
    temp->left=convertBstUtil(root,n/2);
    temp->right=convertBstUtil(ptr->next,n-n/2-1);
    return temp;
}
nodet* convertBst(node* root){
    if(!root)
        return NULL;
    int n=countNodes(root);
    return convertBstUtil(root,n);
}
void createList(node** root,int data){
    if(*root){
        node* ptr=*root;
        for(;ptr->next;ptr=ptr->next);
        ptr->next=new node(data);
    }
    else *root=new node(data);
}
void levelOrder(nodet* root){
    if(root){
        queue<nodet*> q;
        q.push(root);
        while(!q.empty()){
            int LevelSize=q.size();
            while(LevelSize--){
                nodet* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }
    }
}
void printList(node* root){
    for(;root;root=root->next)
        cout<<root->data<<" ";
}
void inOrder(nodet* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int main(){
    node* root=NULL;
    int n;
    cin>>n;
    while(n--){
        int temp;
        cin>>temp;
        createList(&root,temp);
    }
    nodet* roott=convertBst(root);
    levelOrder(roott);
    return 0;
}
