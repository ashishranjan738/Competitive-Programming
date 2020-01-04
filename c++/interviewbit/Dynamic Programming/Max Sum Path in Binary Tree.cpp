#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    int Solution::maxPathSum(TreeNode *A);
};

// Given a binary tree T, find the maximum path sum.

// The path may start and end at any node in the tree.

// Input Format:

// The first and the only argument contains a pointer to the root of T, A.
// Output Format:

// Return an integer representing the maximum sum path.
// Constraints:

// 1 <= Number of Nodes <= 7e4
// -1000 <= Value of Node in T <= 1000
// Example :

// Input 1:

//        1
//       / \
//      2   3

// Output 1:
//      6

// Explanation 1:
//     The path with maximum sum is: 2 -> 1 -> 3

// Input 2:

//        -10
//        /  \
//      -20  -30

// Output 2:
//     -10

// Explanation 2
//     The path with maximum sum is: -10

int solve(TreeNode *root, int &ans)
{
    // Hint:
    // For each node there can be four ways that the max path goes through the node:
    // 1. Node only
    // 2. Max path through Left Child + Node
    // 3. Max path through Right Child + Node
    // 4. Max path through Left Child + Node + Max path through Right ChildÎÎ
    if (!root)
        return 0;
    int leftSum = solve(root->left, ans);
    int rightSum = solve(root->right, ans);
    // if the path passes through any of the left
    // or right child
    int partialSum = max(max(leftSum, rightSum) + root->val, root->val);
    // if the path includes both left and right child
    // root is a part of it
    int totalSum = max(partialSum, root->val + leftSum + rightSum);
    ans = max(ans, totalSum);
    // we need to return the partial sum because returning
    // totalSum will split the path in more than 2 ends
    return partialSum;
}
int Solution::maxPathSum(TreeNode *A)
{
    int ans = INT_MIN;
    solve(A, ans);
    return ans;
}

// Reference:
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/