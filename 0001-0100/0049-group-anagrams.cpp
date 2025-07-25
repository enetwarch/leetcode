#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/group-anagrams/
class Solution {
   public:
    std::vector<std::vector<std::string>> groupAnagrams(
        std::vector<std::string>& strs) {
        // For complexity, n will be strings, k will be their length.
        // Space complexity is O(nk) for both the map and output.
        std::unordered_map<std::string, std::vector<std::string>> map;

        // Sorts each string to serve as a key for the hashmap.
        // Anagrams will always have the same sorted string.
        // Time complexity will be O(nk log(k)); simple loop with sorting.
        for (auto str : strs) {
            std::string sorted = str;
            std::sort(sorted.begin(), sorted.end());

            map[sorted].push_back(str);
        }

        // Output parsing part from map to vector.
        std::vector<std::vector<std::string>> soln;
        for (auto entry : map) {
            soln.push_back(entry.second);
        }

        return soln;
    }
};
