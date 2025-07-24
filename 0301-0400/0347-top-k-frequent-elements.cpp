#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
   public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
        }

        std::vector<std::pair<int, int>> pairs;
        for (auto& pair : count) {
            pairs.push_back({pair.second, pair.first});
        }
        std::sort(pairs.rbegin(), pairs.rend());

        std::vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(pairs[i].second);
        }
        return answer;
    }
};
