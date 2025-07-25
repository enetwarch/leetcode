#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Store the number and their frequency with increments.
        // Space complexity is O(n) worst case.
        std::unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }

        // Extract the map and reverse the key: value pairs.
        // Then reverse sort to show highest frequency first.
        std::vector<std::pair<int, int>> pairs;
        for (auto& pair : count) {
            pairs.push_back({pair.second, pair.first});
        }
        std::sort(pairs.rbegin(), pairs.rend());

        // Extract correct answers based on requirements by k.
        // All algorithms are O(n) or O(n log(n)) for sorting.
        std::vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(pairs[i].second);
        }

        return answer;
    }
};
