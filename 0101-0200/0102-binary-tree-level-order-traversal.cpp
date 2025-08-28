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

// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
   public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        // Queue is used to enable the BFS algorithm.
        // Node pointer and depth are kept track of in the queue.
        // Space complexity is O(n); could potentially store all nodes.
        if (root == nullptr) return {};
        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push({root, 0});

        // BFS algorithm is performed here to get all level vals.
        // Stores the val in the 2d array based on its depth.
        // Time complexity is O(n); iterates through all nodes.
        std::vector<std::vector<int>> levels;
        while (!queue.empty()) {
            TreeNode* pointer = queue.front().first;
            int depth = queue.front().second;
            queue.pop();

            if (pointer == nullptr) continue;
            if (levels.size() <= depth) levels.push_back({});
            levels[depth].push_back(pointer->val);

            int next = depth + 1;
            queue.push({pointer->left, next});
            queue.push({pointer->right, next});
        }

        return levels;
    }
};
