#include <unordered_map>

/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// https://leetcode.com/problems/copy-list-with-random-pointer/
class Solution {
   public:
    Node* copyRandomList(Node* head) {
        // A hashmap is used to keep track of node pointers.
        // Space complexity is O(n); stores each node.
        if (head == nullptr) return nullptr;
        std::unordered_map<Node*, Node*> nodes;

        // Each node in the list will have new copies.
        // These new copies will be mapped with the original.
        Node* pointer = head;
        while (pointer != nullptr) {
            nodes[pointer] = new Node(pointer->val);
            pointer = pointer->next;
        }
        pointer = head;

        // The nodes get their next and rand pointer allocated here.
        // The hashmap is used to get the newly allocated nodes.
        // Time complexity is O(n); loops linearly.
        Node* copy_head = nodes[pointer];
        Node* copy_pointer = copy_head;
        while (pointer != nullptr) {
            copy_pointer->next = nodes[pointer->next];
            copy_pointer->random = nodes[pointer->random];

            copy_pointer = copy_pointer->next;
            pointer = pointer->next;
        }

        return copy_head;
    }
};
