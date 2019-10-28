#include<bits/stdc++.h>
using namespace std;
#define sizearr(a) sizeof(a)/sizeof(a[0])
struct node{
    int data;
    node* down;
    node* next;
};
node* getNode(int data){
    node* ret=new node;
    ret->next=NULL;
    ret->down=NULL;
    ret->data=data;
return ret;
}
void makeList(node** root,int data){
    if(*root){
        node* temp=*root;
        while(temp->next)
            temp=temp->next;
        temp->next=getNode(data);
    }else *root=getNode(data);
}
void flatten(node* root){
    if(root){
        node* curr=root;
        node* tail=root;
        while(tail->next)
            tail=tail->next;
        while(curr!=tail){
            if(curr->down){
                tail->next=curr->down;
                node* temp=curr->down;
                while(temp->next)
                    temp=temp->next;
                tail=temp;
            }
            curr=curr->next;
        }
    }
}
void print(node* root){
    while(root){
        cout<<root->data<<" ";
        root=root->next;
    }
}
void makeArrList(node** root,int a[],int n){
    for(int i=0;i<n;i++){
        makeList(&(*root),a[i]);
    }
}
void flattenList(node *head)
{
    /*Base case*/
    if (head == NULL)
       return;

    node *tmp;

    /* Find tail node of first level linked list */
    node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    // One by one traverse through all nodes of first level
    // linked list till we reach the tail node
    node *cur = head;
    while (cur != tail)
    {
        // If current node has a child
        if (cur->down)
        {
            // then append the child at the end of current list
            tail->next = cur->down;

            // and update the tail to new last node
            tmp = cur->down;
            while (tmp->next)
                tmp = tmp->next;
            tail = tmp;
        }

        // Change current node
        cur = cur->next;
    }
}
int main(){
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};

    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    node* head4=NULL;
    node* head5=NULL;
    node* head6=NULL;
    node* head7=NULL;
    node* head8=NULL;

    makeArrList(&head1,arr1,sizearr(arr1));
    makeArrList(&head2,arr2,sizearr(arr2));
    makeArrList(&head3,arr3,sizearr(arr3));
    makeArrList(&head4,arr4,sizearr(arr4));
    makeArrList(&head5,arr5,sizearr(arr5));
    makeArrList(&head6,arr6,sizearr(arr6));
    makeArrList(&head7,arr7,sizearr(arr7));
    makeArrList(&head8,arr8,sizearr(arr8));

    head1->down = head2;
    head1->next->next->next->down = head3;
    head3->down = head4;
    head4->down = head5;
    head2->next->down = head6;
    head2->next->next->down = head7;
    head7->down = head8;

    flatten(head1);
    print(head1);


return 0;}
