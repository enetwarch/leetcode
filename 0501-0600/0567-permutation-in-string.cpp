#include <string>
#include <unordered_map>

// https://leetcode.com/problems/permutation-in-string/
class Solution {
   public:
    bool checkInclusion(std::string s1, std::string s2) {
        // Space complexity is O(n); n is size of s1.
        // Pre allocates the requirement for window.
        std::unordered_map<char, int> letters;
        for (auto character : s1) {
            letters[character]++;
        }

        // The window hashmap keeps track of current contents.
        // Time complexity O(n); right pointer is always moving.
        int left = 0, right = 0;
        std::unordered_map<char, int> window;
        while (right < s2.size()) {
            // This conditional checks if the char is apart of the substring.
            // Because of that, the hashmap will be empty most of the time.
            if (!letters.contains(s2[right])) {
                if (!window.empty()) window.clear();
                left = ++right;
            } else {
                window[s2[right++]]++;
                if ((right - left) != s1.size()) continue;

                // Checks if char count matches in the window.
                int matching = 0;
                for (auto& [key, value] : letters) {
                    if (window[key] == value) matching += value;
                }

                // Important segment and the only way to evaluate true.
                // Left pointer will increment once to maintain s1 size.
                if (matching == s1.size()) return true;
                window[s2[left++]]--;
            }
        }

        return false;
    }
};
