#include <algorithm>
#include <vector>

// https://leetcode.com/problems/3sum/
class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        // We sort the array first to make the two pointer strategy work.
        // Space complexity could be O(n^2) at worst for storing the output.
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> triplets;

        // Three pointers will be used here l(eft), m(id), and r(ight).
        // The l(eft) pointer keeps the other pointers corralled.
        // With this setup, m(id) and r(ight) act like two sum solvers.
        // Time complexity is O(n^2) as it is essentially a nested two sum.
        for (int l = 0; l < nums.size(); l++) {
            if (nums[l] > 0) break;
            if (l > 0 && nums[l] == nums[l - 1]) continue;

            int m = l + 1;
            int r = nums.size() - 1;
            while (r > m) {
                int sum = nums[l] + nums[m] + nums[r];
                if (sum == 0) {
                    triplets.push_back({nums[l], nums[m], nums[r]});

                    // These blocks help avoid repeating triplets.
                    // m(id) and r(ight) should move to the next unique numbers.
                    m++;
                    r--;
                    while (m < r && nums[m] == nums[m - 1]) m++;
                    while (r > m && nums[r] == nums[r + 1]) r--;
                } else {
                    sum > 0 ? r-- : m++;
                }
            }
        }

        return triplets;
    }
};
