#include <queue>

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
*/

// https://leetcode.com/problems/same-tree/
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Queues are used to enable BFS algorithm.
        // Space complexity is O(n*m); queues stores both tree nodes.
        if (p == nullptr && q != nullptr) return false;
        std::queue<TreeNode*> pqueue;
        std::queue<TreeNode*> qqueue;
        pqueue.push(p);
        qqueue.push(q);

        // This loop performs the BFS algorithm on both trees.
        // Time complexity is O(n); Iterates on both tree nodes at once.
        while ((!pqueue.empty())) {
            TreeNode* ppointer = pqueue.front();
            TreeNode* qpointer = qqueue.front();
            pqueue.pop();
            qqueue.pop();

            // This statement is the guard clause to check inequality.
            // If one of the nodes are null and the other isn't, return false.
            // If the values are not equal, return false.
            // Also checks left and right pointers in advance if they are null.
            if ((ppointer == nullptr ^ qpointer == nullptr) ||
                ((ppointer != nullptr && qpointer != nullptr) &&
                 ((ppointer->val != qpointer->val) ||
                  (ppointer->left == nullptr ^ qpointer->left == nullptr) ||
                  (ppointer->right == nullptr ^ qpointer->right == nullptr))))
                return false;

            if (ppointer != nullptr && qpointer != nullptr) {
                pqueue.push(ppointer->left);
                pqueue.push(ppointer->right);
                qqueue.push(qpointer->left);
                qqueue.push(qpointer->right);
            }
        }

        return true;
    }
};
