#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> triplets;

        for (int l = 0; l < nums.size(); l++) {
            if (nums[l] > 0) break;
            if (l > 0 && nums[l] == nums[l - 1]) continue;

            int m = l + 1, r = nums.size() - 1;
            while (r > m) {
                int sum = nums[l] + nums[m] + nums[r];
                if (sum == 0) {
                    triplets.push_back({nums[l], nums[m], nums[r]});

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
