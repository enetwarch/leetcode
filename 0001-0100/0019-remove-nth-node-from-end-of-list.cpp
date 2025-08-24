/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Keeps track of pointer node for length - n index.
        // Index is used to determine when to advance pointer node.
        // Pointer node is the node before the actual n-index node.
        // Space complexity is O(1); does not scale with input.
        ListNode* left = nullptr;
        ListNode* right = head;
        int index = 1;

        // If the last node is encountered, n-index node will be deleted.
        // Deletion happens by advancing the ->next pointer.
        // Time complexity is O(n); traverses the list linearly.
        while (right != nullptr) {
            if (right->next == nullptr) {
                if (left == nullptr) {
                    head = head->next;
                } else {
                    left->next = left->next->next;
                }
                break;
            }

            // Left node will remain until index is caught up to n.
            // It will then keep moving 1 index at a time.
            // The right pointer will always keep traversing.
            if (index == n) {
                left = left == nullptr ? head : left->next;
            } else {
                index++;
            }
            right = right->next;
        }

        return head;
    }
};
