#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left,*right;
    node(int a){
        data=a;
        left=right=NULL;
    }
};
void levelOrder(node* root){
    if(root){
        cout<<"Level Tree Traversal start \n";
        queue<node*> q;
        q.push(root);
        while(1){
            if(q.empty())
                break;
            int NodeCount=q.size();
            while(NodeCount>0){
                node*temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
                NodeCount--;
            }
            cout<<endl;
        }
    cout<<"Level Tree traversal stop \n";
    }
}
void swapSubtreesOfLevel(node *root,int k)
{
    if(! root)
        return;

    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);
    int level = 1;

    while(! Q.empty())
    {
        node *tmp = Q.front();
        Q.pop();

        if(tmp == NULL)
        {
            if(! Q.empty())
            {
                Q.push(NULL);
            }
            level++;
        }
        else
        {
            if(level == k)
            {
                node *sw = tmp->left;
                tmp->left = tmp->right;
                tmp->right = sw;
            }

            if(tmp->left)
                Q.push(tmp->left);

            if(tmp->right)
                Q.push(tmp->right);
        }
    }
}
void modifyTree(node* root,int curr,int depth){
    if(root){
        if(curr==depth){
            node* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        else{
            if(root->left)modifyTree(root->left,curr+1,depth);
            if(root->right)modifyTree(root->right,curr+1,depth);
        }
    }
}
void inOrder(node* root){
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}
int calDepth(node* root){
    if(root){
        return 1+max(calDepth(root->left),calDepth(root->right));
    }
    else return 0;
}
int main(){
    int n;
    cin>>n;
    queue<node*> q;
    node* root=new node(1);
    q.push(root);
    while(n&&!q.empty()){
        node* temp=q.front();
        q.pop();
        int a,b;
        cin>>a>>b;
        if(a!=-1){
            temp->left=new node(a);
            q.push(temp->left);
        }
        if(b!=-1){
            temp->right=new node(b);
            q.push(temp->right);
        }
        n--;
    }
    //levelOrder(root);
    int depth=calDepth(root);
    //cout<<depth<<endl;
   // inOrder(root);
    cin>>n;
    while(n--){
        int count=1;
        int temp;
        cin>>temp;
        while(temp<=depth){
            swapSubtreesOfLevel(root,temp);
            count++;
            temp*=count;
        }
        inOrder(root);
        cout<<endl;
    }
    return 0;
}
