// { Driver Code Starts
// C++ Program to print Bottom View of Binary Tree
#include <bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data;           //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root);

Node *make_tree()
{
    int n;
    cin >> n;

    Node *head = NULL;
    queue<Node *> q;

    for (; n > 0; n--)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;

        if (!head)
        {
            head = new Node(a);
            q.push(head);
        }

        Node *pick = q.front();
        q.pop();

        if (c == 'L')
        {
            pick->left = new Node(b);
            q.push(pick->left);
        }

        n--;
        if (!n)
            break;

        cin >> a >> b >> c;

        if (c == 'R')
        {
            pick->right = new Node(b);
            q.push(pick->right);
        }
    }
    return head;
}

/* Driver program to test size function*/
int main()
{
    int t;
    struct Node *child;
    scanf("%d\n", &t);
    while (t--)
    {

        Node *root = make_tree();
        bottomView(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

struct NodeWrapper
{
    Node *n;
    int HD;
};
/*
The key idea is to calculate the horizontal distance from root and
store the last node with that horizontal distance
*/

// Method that prints the bottom view.
void bottomView(Node *root)
{
    if (!root)
        return;
    queue<NodeWrapper> q;
    map<int, int> m;
    q.push({root, 0});
    int minHD = INT_MAX, maxHD = INT_MIN;
    while (!q.empty())
    {
        NodeWrapper temp = q.front();
        q.pop();
        minHD = min(minHD, temp.HD);
        maxHD = max(maxHD, temp.HD);
        m[temp.HD] = (temp.n)->data;
        if ((temp.n)->left)
            q.push({(temp.n)->left, temp.HD - 1});
        if ((temp.n)->right)
            q.push({(temp.n)->right, temp.HD + 1});
    }
    for (int i = minHD; i <= maxHD; i++)
        cout << m[i] << " ";
}