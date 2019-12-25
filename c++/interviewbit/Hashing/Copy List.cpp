#include <bits/stdc++.h>
using namespace std;

struct RandomListNode
{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
public:
    RandomListNode *Solution::copyRandomList(RandomListNode *A);
};

// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

// Return a deep copy of the list.

// Example

// Given list

//    1 -> 2 -> 3
// with random pointers going from

//   1 -> 3
//   2 -> 1
//   3 -> 1
// You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.

RandomListNode *Solution::copyRandomList(RandomListNode *A)
{
    map<RandomListNode *, RandomListNode *> m;
    for (RandomListNode *i = A; i != NULL; i = i->next)
    {
        m[i] = new RandomListNode(i->label);
    }
    RandomListNode *ans, *ptr;
    ans = ptr = NULL;
    for (RandomListNode *i = A; i != NULL; i = i->next)
    {
        if (ans == NULL)
        {
            ans = m[i];
            ptr = ans;
        }
        if (i->next != NULL)
        {
            ptr->next = m[i->next];
        }
        if (i->random != NULL)
        {
            ptr->random = m[i->random];
        }
        ptr = ptr->next;
    }
    return ans;
}
