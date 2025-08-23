/*
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
*/

// https://leetcode.com/problems/reverse-linked-list/
class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        // Keep track of current and previous node.
        // Space complexity is O(1); does not scale.
        ListNode* previous_node = nullptr;
        ListNode* current_node = head;

        // Next node is first stored to allow the current node to advance.
        // Simply turns the pointer of the current node to the previous.
        // After that, the current node will advance to the stored next node.
        // Time complexity is O(n); linearly iterates through each node.
        while (current_node != nullptr) {
            ListNode* next_node = current_node->next;
            current_node->next = previous_node;

            previous_node = current_node;
            current_node = next_node;
        }

        return previous_node;
    }
};
