#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        // This should be O(n) time and space complexity.
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
