#include <limits>
#include <vector>

// https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
   public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        // Space complexity is O(1); no scaling from input.
        int min_length = std::numeric_limits<int>::max();

        // Sliding window starts at 0 index and is kept track of.
        // Time complexity is O(n); only moves forward.
        int sum = nums[0];
        int left = 0, right = 0;
        while (left < nums.size()) {
            int length = right - left + 1;
            if (sum >= target && length < min_length) {
                min_length = length;
            }

            // This conditional tries to keep the window small.
            // It also tries to keep the sum close to the target.
            if (right < nums.size() - 1 && sum < target) {
                sum += nums[++right];
            } else {
                sum -= nums[left++];
            }
        }

        if (min_length == std::numeric_limits<int>::max()) return 0;
        return min_length;
    }
};
