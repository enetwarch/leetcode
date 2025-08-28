#include <stack>
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

// https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
   public:
    int maxDepth(TreeNode* root) {
        // A stack is used instead of the call stack for DFS.
        // The stack keeps track of both the pointer and depth.
        // Space complexity is O(n); stacks can store all nodes.
        if (root == nullptr) return 0;
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});

        // This loop runs until no more unexplored node remains.
        // Current item in the stack is allocated to pointer and depth.
        // Time complexity is O(n); iterates through all the nodes.
        int max = 0, depth = 0;
        TreeNode* pointer = nullptr;
        while (!stack.empty()) {
            pointer = stack.top().first;
            depth = stack.top().second;
            stack.pop();

            // Left and right nodes are stored in the stack.
            // The next depth will be in the pair as well.
            // Max is updated if current depth is bigger.
            if (pointer != nullptr) {
                if (depth > max) max = depth;
                int next = depth + 1;
                stack.push({pointer->left, next});
                stack.push({pointer->right, next});
            }
        }

        return max;
    }
};
