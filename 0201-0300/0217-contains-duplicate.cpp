#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/contains-duplicate/
class Solution {
   public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Best case scenario, hashsets have O(1) on most operations.
        // Space complexity is O(n) worst case scenario.
        std::unordered_set<int> set;

        // Time complexity is O(n) if there is no duplicate.
        for (int num : nums) {
            if (set.contains(num)) return true;
            set.insert(num);
        }

        return false;
    }
};
