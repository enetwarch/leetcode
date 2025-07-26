#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/find-all-anagrams-in-a-string/
class Solution {
   public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        // Space complexity is O(n); size of s at most.
        std::vector<int> anagram_indices;

        // Extract characters from p arg to hashmap.
        // Will be helpful for matching in the window.
        std::unordered_map<char, int> letters;
        for (auto character : p) {
            letters[character]++;
        }

        // Right window pointer checks for unique characters.
        // Left window pointer stays to keep track of length.
        // Time complexity is O(n); only moves forward.
        int left = 0, right = 0;
        std::unordered_map<char, int> window;
        while (right < s.size()) {
            // Keeps moving the pointers if char isn't in p.
            // Important to avoid unnecessary calculations.
            if (!letters.contains(s[right])) {
                if (!window.empty()) window.clear();
                left = ++right;
            } else {
                window[s[right++]]++;
                if (right - left != p.size()) continue;

                // Checks if all characters match the anagram's.
                // If yes, push that index in the answer vector.
                int matching = 0;
                for (auto& [key, value] : letters) {
                    if (window[key] == value) matching += value;
                }

                if (matching == p.size()) {
                    anagram_indices.push_back(left);
                }

                // Keeps the window moving and within p.size().
                window[s[left++]]--;
            }
        }

        return anagram_indices;
    }
};
