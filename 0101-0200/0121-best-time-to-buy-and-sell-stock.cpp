#include <limits>
#include <vector>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
   public:
    int maxProfit(std::vector<int>& prices) {
        // Space complexity is O(1) as it does not scale.
        // Int max is used to find an immediate lowest.
        int lowest = std::numeric_limits<int>::max();
        int profit = 0;

        // Will keep track of the lowest and go from there.
        // Time complexity is O(n); simple for loop.
        for (auto price : prices) {
            if (price < lowest) lowest = price;

            int stonk = price - lowest;
            if (stonk > profit) profit = stonk;
        }

        return profit;
    }
};
