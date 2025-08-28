#include <algorithm>
#include <stack>

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right
(right) {}
};
*/

// https://leetcode.com/problems/invert-binary-tree/
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        // Stack is used as a replacement to the call stack.
        // Space complexity is O(n); stores all nodes in stack.
        if (root == nullptr) return root;
        std::stack<TreeNode*> stack;
        stack.push(root);

        // An iterative approach was used to avoid exploding the call stack.
        // Stack is used here to store the deeper immediate nodes found.
        // Constantly swaps pointers from the nodes stored in the stack.
        // Time complexity is O(n); loops iteratively through all the nodes.
        TreeNode* pointer = nullptr;
        while (!stack.empty()) {
            if (pointer != nullptr) {
                std::swap(pointer->left, pointer->right);
            }

            pointer = stack.top();
            stack.pop();
            if (pointer != nullptr) {
                stack.push(pointer->left);
                stack.push(pointer->right);
            }
        }

        return root;
    }
};
