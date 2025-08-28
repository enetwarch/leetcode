#include <queue>
#include <utility>

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

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
class Solution {
   public:
    int goodNodes(TreeNode* root) {
        // Queue is used to enable the BFS algorithm.
        // It keeps track of the pointer node and the highest val so far.
        // Space complexity is O(n); could store all nodes.
        if (root == nullptr) return 0;
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push({root, root->val});

        // A standard BFS algorithm is implemented here.
        // Time complexity is O(n); iterates through all the nodes.
        int good_nodes = 0;
        while (!queue.empty()) {
            TreeNode* pointer = queue.front().first;
            int highest = queue.front().second;
            queue.pop();

            // Updates the highest if the current val >= highest.
            // Adds one point to good_nodes as well.
            if (pointer->val >= highest) {
                highest = pointer->val;
                good_nodes++;
            }

            if (pointer->left) queue.push({pointer->left, highest});
            if (pointer->right) queue.push({pointer->right, highest});
        }

        return good_nodes;
    }
};
