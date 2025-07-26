#include <string>
#include <unordered_set>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        // Hashset keeps track of window elements.
        // Space complexity is O(n) worst case scenario.
        std::unordered_set<char> window;
        int longest = 0;

        // Right window pointer keeps moving to look for duplicates.
        // Left pointer stays to keep track of the length.
        // Move left to duplicate + 1 if right encounters a duplicate.
        // Time complexity is O(n); linear for loop.
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (!window.contains(s[right])) {
                window.insert(s[right]);
            } else {
                int length = right - left;
                if (length > longest) longest = length;

                // Keep moving left window until the duplicate.
                // Also erase elements going out of window.
                while (s[left] != s[right]) {
                    window.erase(s[left]);
                    left++;
                }
                left++;
            }
        }

        // Do one last calculation on the far right window.
        int length = s.size() - left;
        if (length > longest) longest = length;
        return longest;
    }
};
