#include <vector>

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
   public:
    int findMin(std::vector<int>& nums) {
        // Initialize standard binary search pointers.
        // Space complexity O(1); does not scale.
        int left = 0;
        int right = nums.size() - 1;

        // Mid pointer is calculated as usual in binary search.
        // Mid is still kept in the search space when moving right pointer.
        // Time complexity O(log n); constantly halves search space.
        while (left < right) {
            int mid = left + ((right - left) / 2);
            nums[right] > nums[mid] ? right = mid : left = mid + 1;
        }

        return nums[left];
    }
};
