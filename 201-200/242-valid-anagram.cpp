#include <string>
#include <unordered_map>

class Solution {
   public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        std::unordered_map<char, int> map;

        // All map values should equalize to 0 if it is an anagram.
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
            map[t[i]]--;
        }

        for (auto c : map) {
            if (c.second != 0) return false;
        }

        return true;
    }
};
