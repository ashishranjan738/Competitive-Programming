#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int t){
        data=t;
        left=right=NULL;
    }
};
void findDiagonals(node* root,int ref,map<int,int> &m){
    if(!root)
        return;
    m[ref]+=root->data;
    if(root->left)findDiagonals(root->left,ref+1,m);
    if(root->right)findDiagonals(root->right,ref,m);
}
void printDiagonalSum(node* root){
    if(!root)
        return;
    map<int,int> m;
    findDiagonals(root,0,m);
    for(auto it=m.begin();it!=m.end();it++){
        cout<<(*it).second<<endl;
    }
}
void levelOrder(node* root){
    if(root){
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            while(levelSize--){
                node* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                cout<<temp->data<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->left->left=new node(9);
    root->left->left->right=new node(10);
    root->left->right=new node(6);
    root->left->right->left=new node(11);
    root->right=new node(3);
    root->right->right=new node(5);
    root->right->left=new node(4);
    root->right->left->right=new node(7);
    root->right->left->left=new node(12);
    levelOrder(root);
    cout<<endl;
    printDiagonalSum(root);
    return 0;
}
