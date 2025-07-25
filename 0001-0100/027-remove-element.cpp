#include <vector>

// https://leetcode.com/problems/remove-element/
class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        // Uses a simple two pointer strategy.
        // Space complexity is O(1); no scaling.
        // Time complexity is O(n); based on right pointer.
        int l = 0, r = 0;
        while (true) {
            while (r < nums.size() && nums[r] == val) r++;
            if (r >= nums.size()) break;
            nums[l++] = nums[r++];
        }
        nums.erase(nums.begin() + l, nums.end());

        return nums.size();
    }
};
