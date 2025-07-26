#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
   public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        // This solution is a bit expensive on space complexity.
        // Space complexity is O(n); * 10 is ignored.
        std::unordered_map<std::string, int> sequences;
        std::string current_sequence = s.substr(0, 9);

        // Keep adding the fixed's window current sequence as keys.
        // Time complexity O(n); right pointer is always moving.
        for (int right = 9; right < s.size(); ++right) {
            current_sequence += s[right];
            sequences[current_sequence]++;
            current_sequence.erase(0, 1);
        }

        // Extract the repeat sequences from the hashmap to vector.
        std::vector<std::string> repeats;
        for (auto& [key, value] : sequences) {
            if (value > 1) repeats.push_back(key);
        }

        return repeats;
    }
};
