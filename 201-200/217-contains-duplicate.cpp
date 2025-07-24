#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>& numbers) {
        // Best case scenario, hashsets have O(1) look up and insertion time.
        // Allocation is like this to try to avoid collisions and rehashing.
        // NOLINTNEXTLINE(bugprone-narrowing-conversions)
        std::unordered_set<int> hashSet(numbers.size() * 1.5);

        for (int number : numbers) {
            if (hashSet.contains(number)) return true;
            hashSet.insert(number);
        }

        return false;
    }
};
