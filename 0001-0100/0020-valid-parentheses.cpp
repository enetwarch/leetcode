#include <stack>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/valid-parentheses/description/
class Solution {
   public:
    bool isValid(std::string s) {
        // Guard clause to return early if the length is odd.
        // This is because each parenthesis must have a closing counterpart.
        if (s.length() % 2 != 0) return false;

        // Stack is initialized to keep track of valid parenthesess.
        // A map is used for O(1) lookups, but it does up space complexity.
        // There is a tradeoff between space complexity and faster lookups.
        std::stack<char> stack;
        std::unordered_map<char, char> par_map = {
            {'(', ')'}, {'{', '}'}, {'[', ']'}};

        // This algorithm is O(n) because it only checks the string once.
        // Checks if the parentheses are closed off correctly.
        for (auto c : s) {
            if (par_map.contains(c)) {
                stack.push(c);
            } else {
                if (stack.empty()) return false;
                if (par_map[stack.top()] != c) return false;
                stack.pop();
            }
        }

        // If even one parenthesis isn't closed, the stack won't be empty.
        return stack.empty();
    }
};
