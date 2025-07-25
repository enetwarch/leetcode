#include <string>
#include <unordered_map>

// https://leetcode.com/problems/roman-to-integer/
class Solution {
   public:
    int romanToInt(std::string s) {
        // A map is used for getting the values of each char.
        // Space complexity is O(1); does not scale.
        static std::unordered_map<char, int> value_map = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        // Keeps track of the previous to know when to subtract.
        // Plays a role if a lower roman is placed before a higher one.
        // Algorithm is O(n); simple for loop.
        int answer = 0;
        int prev = 0;
        for (auto c : s) {
            int value = value_map[c];
            answer += value - (value > prev ? prev * 2 : 0);
            prev = value;
        }

        return answer;
    }
};
