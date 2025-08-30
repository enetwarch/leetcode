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

// https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
   public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // A stack is used to enable the DFS algorithm.
        // Space complexity is O(n); can store all nodes from root.
        if (subRoot == nullptr) return true;
        if (root == nullptr) return false;
        std::stack<TreeNode*> stack;
        stack.push(root);

        // Checks all nodes in root and compares it to subRoot.
        // If the helper isSameTree returns true, return true.
        // Time complexity is O(n*m); where m is the nodes in subRoot.
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();

            if (isSameTree(node, subRoot)) return true;

            if (node->left) stack.push(node->left);
            if (node->right) stack.push(node->right);
        }

        return false;
    }

   private:
    bool isSameTree(TreeNode* mainRoot, TreeNode* subRoot) {
        // A stack is used here to enable the DFS algorithm.
        // Space complexity for this method is O(n); can store all nodes.
        if (subRoot == nullptr) return true;
        if (mainRoot == nullptr) return false;
        std::stack<std::pair<TreeNode*, TreeNode*>> stack;
        stack.push({mainRoot, subRoot});

        // DFS checks and validates if the nodes are actual subtrees.
        // Time complexity is O(n); could look through all subroot nodes.
        while (!stack.empty()) {
            TreeNode* main = stack.top().first;
            TreeNode* sub = stack.top().second;
            stack.pop();

            if ((main->val != sub->val) ||
                (main->left == nullptr ^ sub->left == nullptr) ||
                (main->right == nullptr ^ sub->right == nullptr))
                return false;

            if (sub->left) stack.push({main->left, sub->left});
            if (sub->right) stack.push({main->right, sub->right});
        }

        return true;
    }
};
