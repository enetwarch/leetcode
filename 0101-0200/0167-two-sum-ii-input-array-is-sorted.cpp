#include <vector>

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        // Uses the two pointer strategy to pinpoint the answer.
        // Each input is assumed to be sorted as the description specified.
        // Space complexity is O(1) as it does not scale with input.
        int left = 0;
        int right = numbers.size() - 1;

        // Moves the low pointer if the sum is undershooting, and vice versa.
        // Time complexity is O(n) worst case; simple for loop.
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return {left + 1, right + 1};

            sum < target ? left++ : right--;
        }

        // This return statement should not be reached.
        return {0, 0};
    }
};
