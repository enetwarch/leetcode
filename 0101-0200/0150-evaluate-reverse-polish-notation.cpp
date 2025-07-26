#include <stack>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
   public:
    int evalRPN(std::vector<std::string>& tokens) {
        // Space complexity is O(n) worst case.
        std::stack<int> stack;

        // Pushes integers up the stack if the token is a number.
        // Otherwise, pop 2 nums in the stack and do the operation.
        // Time complexity is O(n); simple for loop.
        for (auto token : tokens) {
            if (!(token == "+" || token == "-" || token == "*" ||
                  token == "/")) {
                stack.push(std::stoi(token));
                continue;
            }

            int right_operand = stack.top();
            stack.pop();
            int left_operand = stack.top();
            stack.pop();

            // A switch case can work here, but break adds more lines.
            if (token == "+") {
                stack.push(left_operand + right_operand);
            } else if (token == "-") {
                stack.push(left_operand - right_operand);
            } else if (token == "*") {
                stack.push(left_operand * right_operand);
            } else if (token == "/") {
                stack.push(left_operand / right_operand);
            }
        }

        return stack.top();
    }
};
