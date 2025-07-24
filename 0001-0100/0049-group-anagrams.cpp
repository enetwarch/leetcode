#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> soln;
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (auto str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());

            map[sorted].push_back(str);
        }

        for (auto entry : map) {
            soln.push_back(entry.second);
        }

        return soln;
    }
};
