#include <algorithm>
#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
class Solution {
   public:
    int maxSum(std::vector<int>& nums) {
        // We use a hashset to rule out repeating elements.
        // Worst case scenario, the space complexity will be O(n).
        std::unordered_set<int> nums_set;

        // This for loop constantly inserts and queries the set.
        // The guard conditional avoids numbers that will lower the sum.
        int sum = 0;
        for (auto num : nums) {
            if (num <= 0 || nums_set.contains(num)) continue;

            sum += num;
            nums_set.insert(num);
        }

        // Returns the element as it is if it is not zero.
        // The highest number (most likely negative) will be returned otherwise.
        if (sum != 0) return sum;
        return *std::max_element(nums.begin(), nums.end());
    }
};
