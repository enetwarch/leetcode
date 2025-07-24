#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>& nums) {
        // Best case scenario, hashsets have O(1) look up and insertion time.
        // Allocation is like this to try to avoid collisions and rehashing.
        // NOLINTNEXTLINE(bugprone-narrowing-conversions)
        std::unordered_set<int> set(nums.size() * 1.5);

        for (int num : nums) {
            if (set.contains(num)) return true;
            set.insert(num);
        }

        return false;
    }
};
