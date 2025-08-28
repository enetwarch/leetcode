#include <queue>
#include <utility>
#include <vector>

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

// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
   public:
    std::vector<int> rightSideView(TreeNode* root) {
        // Queue is used to enable the BFS algorithm.
        // Both the node pointer and depth are kept track of.
        // Space complexity is O(n); could store all nodes.
        if (root == nullptr) return {};
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push({root, 1});

        // Lowest depth is here to know when to push on the vector.
        // Standard BFS loop that has an if conditional for seen vals.
        // Time complexity is O(n); iterates through all nodes with BFS.
        int lowest_depth = 0;
        std::vector<int> seen;
        while (!queue.empty()) {
            TreeNode* pointer = queue.front().first;
            int depth = queue.front().second;
            queue.pop();

            // The current depth is greater than the lowest.
            // The next depth must be greater than the current one.
            // Only then would it be considered a right side view.
            if (depth > lowest_depth &&
                (queue.empty() || queue.front().second > depth)) {
                seen.push_back(pointer->val);
                lowest_depth++;
            }

            int next = depth + 1;
            if (pointer->left) queue.push({pointer->left, next});
            if (pointer->right) queue.push({pointer->right, next});
        }

        return seen;
    }
};
