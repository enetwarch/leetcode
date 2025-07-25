#include <string>

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
   public:
    int strStr(std::string haystack, std::string needle) {
        // Space complexity should be O(1) as it does not scale.
        int h_size = haystack.size();
        int n_size = needle.size();
        if (h_size < n_size) return -1;

        // This uses a simple two pointer algorithm.
        // Pointers constantly move when there are no matches.
        // Time complexity O(nm); n = h_size, m = n_size.
        int l = 0;
        while (true) {
            while (l < h_size && haystack[l] != needle[0]) l++;
            if (l >= h_size) return -1;

            int r = l;
            while (r - l < n_size && haystack[r] == needle[r - l]) r++;
            if (r - l >= n_size) return l;

            l++;
        }

        // This statement should never be reached.
        return -1;
    }
};
