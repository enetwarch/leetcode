#include <unordered_set>

/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
*/

// https://leetcode.com/problems/linked-list-cycle/
class Solution {
   public:
    bool hasCycle(ListNode* head) {
        // Uses a hashset to keep track of all passed nodes.
        // Space complexity is O(n); can store all nodes;
        std::unordered_set<ListNode*> nodes;

        // Checks if the node is already passed using the hash set.
        // Return true if it is, otherwise insert the current node.
        // Lastly, directly advance the current head to keep iterating.
        // Time complexity is O(n); iterates through all nodes.
        while (head != nullptr) {
            if (nodes.contains(head)) return true;
            nodes.insert(head);
            head = head->next;
        }

        return false;
    }
};
