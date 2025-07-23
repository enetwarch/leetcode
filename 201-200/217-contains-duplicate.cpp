#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool containsDuplicate(std::vector<int>& numbers) {
        std::unordered_set<int> hashSet;

        for (int number : numbers) {
            if (hashSet.contains(number)) return true;
            hashSet.insert(number);
        }

        return false;
    }
};
