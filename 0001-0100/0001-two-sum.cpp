#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/two-sum/
class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Hashmap for O(1) lookup with O(n) space complexity.
        std::unordered_map<int, int> map;

        // Time complexity is O(n) worst case scenario.
        for (int i = 0; i < nums.size(); i++) {
            int correct_addend = target - nums[i];
            if (map.contains(correct_addend)) {
                return {map[correct_addend], i};
            }

            map[nums[i]] = i;
        }

        // The problem should never reach this return statement.
        return {0, 0};
    }
};
