#include <stack>

// https://leetcode.com/problems/min-stack/
class MinStack {
   private:
    // We use two stacks to keep O(1) min operations.
    // Space complexity is O(n); constants are ignored.
    std::stack<int> data;
    std::stack<int> min;

   public:
    MinStack() = default;

    // Here is the main difference between normal and min stack.
    // One stack acts normally, the other pushes the current min.
    void push(int val) {
        data.push(val);
        if (min.empty()) {
            min.push(val);
        } else {
            min.push(val < min.top() ? val : min.top());
        }
    }

    void pop() {
        data.pop();
        min.pop();
    }

    // Both of these operations are O(1) time complexity.
    int top() { return data.top(); }
    int getMin() { return min.top(); }
};
