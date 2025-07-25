#include <algorithm>
#include <vector>

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
   public:
    int removeDuplicates(std::vector<int>& nums) {
        // Space complexity O(1); does not scale.
        int pointer = 0;

        // Check if the previous 2 indexes from pointer is a duplicate.
        // Time complexity O(n); always iterates forward.
        for (auto num : nums) {
            if (pointer >= 2 && num == nums[pointer - 2]) continue;

            nums[pointer] = num;
            pointer++;
        }

        return pointer;
    }
};
