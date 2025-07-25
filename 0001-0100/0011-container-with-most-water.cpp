#include <vector>

// https://leetcode.com/problems/container-with-most-water/
class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        // Space complexity is O(1) as it doesn't scale.
        // Two pointer strategy is used to pinpoint max area.
        int max = 0;
        int l = 0;
        int r = height.size() - 1;

        // The strategy here is to move the smaller pointer inward.
        // Time complexity is O(n) due to the pointers moving.
        while (l < r) {
            int smaller = height[l] < height[r] ? height[l] : height[r];
            int area = smaller * (r - l);
            max = area > max ? area : max;

            height[l] > height[r] ? r-- : l++;
        }

        return max;
    }
};
