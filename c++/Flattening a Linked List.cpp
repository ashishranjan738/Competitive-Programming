#include<bits/stdc++.h>
using namespace std;
struct node{
    node* right;
    node* down;
    int data;
};
node* getNode(int data){
    node* ret = new node;
    ret->down=NULL;
    ret->right=NULL;
    ret->data=data;
return ret;
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->down;
    }
}
node* mergeList(node* root1,node* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    node* result;
    if(root1->data<root2->data){
        result=root1;
        result->down=mergeList(root2,root1->down);
    }
    else{
        result=root2;
        result->down=mergeList(root2->down,root1);
    }
    return result;
}
void flatten(node** root){
    node* ptr=(*root)->right;
    while(ptr){
        (*root)->down=mergeList((*root)->down,ptr);
        ptr=ptr->right;
    }
}
void push (node** head_ref, int new_data)
{
    /* allocate node */
    node* new_node = (node *) malloc(sizeof(node));
    new_node->right = NULL;

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->down = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main(){
  node* root = NULL;

    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );
    flatten(&root);
    print(root);
return 0;}
