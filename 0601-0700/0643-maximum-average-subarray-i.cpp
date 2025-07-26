#include <limits>
#include <vector>

// https://leetcode.com/problems/maximum-average-subarray-i/
class Solution {
   public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        // Space complexity is O(1); does not scale.
        double max_average = std::numeric_limits<int>::min();

        // Initialize window expansion and collect the sum.
        int sum = 0, left = 0, right = 0;
        while (right < k - 1) sum += nums[right++];

        // Left and right always moves and calculates window sum.
        // Time complexity is O(n); right pointer always moves.
        while (right < nums.size()) {
            sum += nums[right++];
            double average = (double)sum / k;
            if (average > max_average) max_average = average;
            sum -= nums[left++];
        }

        return max_average;
    }
};
