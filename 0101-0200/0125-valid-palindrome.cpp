#include <cctype>
#include <string>

class Solution {
   public:
    bool isPalindrome(std::string s) {
        int i = 0;
        for (auto c : s) {
            if (!std::isalnum(c)) continue;
            s[i++] = std::tolower(c);
        }
        s.erase(i);

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
