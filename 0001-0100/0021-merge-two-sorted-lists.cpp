/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // The list1 and list2 arguments are being advanced directly.
        // Space complexity is O(1); does not scale and reused args.
        ListNode* merged = returnLesser(list1, list2);
        ListNode* merged_head = merged;

        // Most of the logic is done in the helper function.
        // Constantly updates the next and advances merged.
        // Time complexity O(n * m); iterates through list1 and 2.
        while (!(list1 == nullptr && list2 == nullptr)) {
            merged->next = returnLesser(list1, list2);
            merged = merged->next;
        }

        return merged_head;
    }

   private:
    ListNode* returnLesser(ListNode*& list1, ListNode*& list2) {
        // Returns lesser immediately if both nodes are nullptrs;
        ListNode* lesser = nullptr;
        if (list1 == nullptr && list2 == nullptr) return lesser;

        // First checks if either of the nodes are null.
        // If one is null, the other will be consumed and advanced.
        // Otherwise, it will normally check which one is lesser.
        // The lesser value will be consumed and advanced.
        if (list1 == nullptr) {
            lesser = list2;
            list2 = list2->next;
        } else if (list2 == nullptr) {
            lesser = list1;
            list1 = list1->next;
        } else if (list1->val < list2->val) {
            lesser = list1;
            list1 = list1->next;
        } else {
            lesser = list2;
            list2 = list2->next;
        }

        return lesser;
    }
};
