#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/contains-duplicate-ii/
class Solution {
   public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        // Hashset is used to keep track of the window.
        // Space complexity is O(n), where n = int k.
        std::unordered_set<int> window;

        // Always checks for duplicates in the current window.
        // Time complexity is O(n); right pointer always moves.
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (window.contains(nums[right])) return true;
            window.insert(nums[right]);

            if ((right - left) < k) continue;
            window.erase(nums[left++]);
        }

        return false;
    }
};
