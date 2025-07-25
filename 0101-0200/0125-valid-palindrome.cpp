#include <cctype>
#include <string>

// https://leetcode.com/problems/valid-palindrome/
class Solution {
   public:
    bool isPalindrome(std::string s) {
        // Space complexity is O(1) as it does not scale.
        // Time complexity is O(n) for both looped algos.

        // Input cleaning algorithm for easier calculation.
        // Directly modifies the input string to save memory.
        int i = 0;
        for (auto c : s) {
            if (!std::isalnum(c)) continue;
            s[i++] = std::tolower(c);
        }
        s.erase(i);

        // Two pointer strategy where we move both pointers inwards.
        // More efficient than reversing a string and comparing.
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }
};
