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
//struct pdata{
//    int data,position;
//};
//vector<pdata> p;
//void vTraversal(node* root,int pos){
//    if(root){
//        p.push_back({root->data,pos});
//        if(root->left)vTraversal(root->left,pos-1);
//        if(root->right)vTraversal(root->right,pos+1);
//    }
//}
//int calLeftDistance(node* root){
//    int i=0;
//    while(root->left){
//        i++;
//        root=root->left;
//    }
//    return -i;
//}
//int calRightDistance(node* root){
//    int i=0;
//    while(root->right){
//        i++;
//        root=root->right;
//    }
//    return i;
//}
//void levelOrder(node* root){
//    if(root){
//        queue<node*> q;
//        q.push(root);
//        while(1){
//            if(q.empty())
//                break;
//            int NodeCount=q.size();
//            while(NodeCount){
//                node* temp=q.front();
//                q.pop();
//                cout<<temp->data<<" ";
//                if(temp->left)q.push(temp->left);
//                if(temp->right)q.push(temp->right);
//                NodeCount--;
//            }
//            cout<<endl;
//        }
//    }
//}
void verticleOrderTraversal(node* root){
    if(root){
        map<int,vector<int>> m;
        queue<pair<node*,int>> q;
        int hd=0;
        q.push(make_pair(root,hd));
        while(!q.empty()){
            pair<node*,int> ptemp=q.front();
            q.pop();
            m[ptemp.second].push_back(ptemp.first->data);
            if(ptemp.first->left)q.push(make_pair(ptemp.first->left,ptemp.second-1));
            if(ptemp.first->right)q.push(make_pair(ptemp.first->right,ptemp.second+1));
        }
        for(auto it=m.begin();it!=m.end();it++){
            for(auto itj=(*it).second.begin();itj!=(*it).second.end();itj++){
                cout<<*itj<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    //levelOrder(root);
//    cout<<calLeftDistance(root);
//    cout<<endl;
//    cout<<calRightDistance(root);
//    cout<<endl;
//vTraversal(root,0);
//    int j=0;
//    for(int i=calLeftDistance(root);i<=calRightDistance(root);i++){
//        for(int j=0;j<p.size();j++){
//            if(p[j].position==i){
//                cout<<p[j].data<<" ";
//            }
//        }
//        cout<<endl;
//    }
    verticleOrderTraversal(root);
    return 0;
}
