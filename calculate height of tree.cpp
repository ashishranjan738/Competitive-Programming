#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left,*right;
};
node* getNode(int data){
    node* ret=new node;
    ret->left=ret->right=NULL;
    ret->data=data;
return ret;
}
void createTree(node** root,int data){
    if(*root){
        if(data<(*root)->data)
            createTree(&(*root)->left,data);
        else createTree(&(*root)->right,data);
    }
    else *root=getNode(data);
}
int maxDepth(node* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}
void inOrder(node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data;
        inOrder(root->right);
    }
}
void levelOrder(node* root,int h){
    if(!root){
        if(h==0)cout<<root->data<<" ";
        else{
            levelOrder(root->left,h-1);
            levelOrder(root->right,h-1);
        }
    }
}
int calHeight(node* root){
    if(!root)
        return -1;
    int l=calHeight(root->left);
    int r=calHeight(root->right);
    return 1+max(l,r);
}
int main(){
    node* root=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        createTree(&root,temp);
    }
    cout<<calHeight(root);
    //int h=calHeight(root);
    //for(int i=0;i<=h;i++)
        //levelOrder(root,i);
return 0;}
