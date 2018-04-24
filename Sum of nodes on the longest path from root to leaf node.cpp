#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
    node(int temp){
        data=temp;
        left=right=NULL;
    }
};
int calMaxSum(node* root,int *sum){
    if(root){
        int left=calMaxSum(root->left,&(*sum));
        int right=calMaxSum(root->right,&(*sum));

            if(left==right)
                *sum+=(left&&right)?max(root->right->data,root->left->data):0;
            else if(left>right)
                *sum+=root->left->data;
            else
                *sum+=root->right->data;
        cout<<root->data<<" "<<*sum<<" "<<left<<" "<<right<<endl;
        return 1+max(left,right);
    }
    else
        return 0;
}
void calMaxSum1(node* root,int &maxsum,int sum,int &height,int len){
    if(root){
        calMaxSum1(root->left,maxsum,sum+root->data,height,len+1);
        calMaxSum1(root->right,maxsum,sum+root->data,height,len+1);
    }
    else if(len==height&&maxsum<sum){
        maxsum=sum;
    }
    else if(len>height){
        maxsum=sum;
        height=len;
    }
}
void levelOrder(node* root){
    if(root){
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int levelSize=q.size();
            while(levelSize){
                node* temp=q.front();
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                cout<<temp->data<<" ";
                levelSize--;
            }
            cout<<endl;
        }
    }
}
int main(){
    node* root=new node(10);
    root->left=new node(20);
    root->right=new node(30);
    root->right->left=new node(40);
    root->right->left->right=new node(70);
    levelOrder(root);
    int sum=0,height=0;
    calMaxSum1(root,sum,0,height,0);
    cout<<sum;
    return 0;
}
