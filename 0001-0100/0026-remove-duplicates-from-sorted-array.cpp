#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        // This uses a simple two pointer strategy.
        // Space complexity is O(1); no scaling from input.
        int l = 0;
        int r = 1;

        // l(eft) will keep track of current unique.
        // r(ight) will keep looking for uniques.
        // Time complexity is O(n); based on right pointer.
        while (true) {
            while (r < nums.size() && nums[l] == nums[r]) r++;
            if (r >= nums.size()) break;
            nums[++l] = nums[r++];
        }
        nums.erase(nums.begin() + l + 1, nums.end());

        return nums.size();
    }
};
