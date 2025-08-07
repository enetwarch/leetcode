#include <vector>

// https://leetcode.com/problems/binary-search/
class Solution {
   public:
    int search(std::vector<int>& nums, int target) {
        // Only stores the left, mid, and right pointers.
        // Space complexity should be O(1) as it does not scale.
        int left = 0;
        int right = nums.size() - 1;

        // Pointer will check the midpoint and adjust accordingly.
        // Will move either left or right pointers based on current value.
        // Time complexity should be O(log n); keeps dividing down by 2.
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] == target) return mid;

            nums[mid] < target ? left = mid + 1 : right = mid - 1;
        }

        return -1;
    }
};
