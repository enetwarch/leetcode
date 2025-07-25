#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
   public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        // Initialize size here to reduce expensive nums.size() calls.
        // Space complexity will be O(n), excluding the answer vector.
        const int size = nums.size();
        std::vector<std::pair<int, int>> fix(size);

        // Initializing the first prefix and suffix removes if conditionals.
        // Prefix multiplies the current number and previous prefix products.
        // Suffix is the opposite and goes from right to left instead.
        // This algorithm is O(n), an improvement from O(n^2) brute force.
        fix[0].first = nums[0];
        fix[size - 1].second = nums[size - 1];
        for (int pre = 1; pre < size; pre++) {
            int suf = size - pre - 1;
            fix[pre].first = fix[pre - 1].first * nums[pre];
            fix[suf].second = fix[suf + 1].second * nums[suf];
        }

        // The answer portion is not included in the complexity.
        // But both are going to be O(n) in space and time complexity.
        // First and last elements are initialized first to avoid conditionals.
        // Prefix and suffix are then multiplied in the for loop.
        std::vector<int> answer(size);
        answer[0] = fix[1].second;
        answer[size - 1] = fix[size - 2].first;
        for (int i = 1; i < size - 1; i++) {
            answer[i] = fix[i - 1].first * fix[i + 1].second;
        }

        return answer;
    }
};
