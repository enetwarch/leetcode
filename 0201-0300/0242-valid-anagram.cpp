#include <string>
#include <unordered_map>

// https://leetcode.com/problems/valid-anagram/
class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        // Early guard clause to potentially save on performance.
        // Space complexity is O(n) where n is size of either strings.
        if (s.size() != t.size()) return false;
        std::unordered_map<char, int> map;

        // All map values should equalize to 0 if it is an anagram.
        // Both this and the checking algo are O(n) in time complexity.
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }

        // Checks if a value in the map is unequalized.
        // It would mean there is a value that isn't equal.
        for (auto c : map) {
            if (c.second != 0) return false;
        }

        return true;
    }
};
