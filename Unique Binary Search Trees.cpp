#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* right,*left;
    TreeNode(int t){
        val=t;
        right=left= nullptr;
    }
};
vector<TreeNode*> solution(int start,int end){
    vector<TreeNode*> res;
    if(start>end){
        res.push_back({NULL});
        return res;
    }
    for(int i=start;i<=end;i++){
        vector<TreeNode*> left=solution(start,i-1);
        vector<TreeNode*> right=solution(i+1,end);
        for(TreeNode* l:left){
            for(TreeNode* r:right){
                auto * temp=new TreeNode(i);
                temp->left=l;
                temp->right=r;
                res.push_back(temp);
            }
        }
    }
    return res;
}
vector<TreeNode*> generateTrees(int n) {
    if(n==0) {
        return
    }
    return solution(1,n);
}
int main(){
    vector<TreeNode*> t=generateTrees(4);
    cout<<t.size();
    return 0;
}