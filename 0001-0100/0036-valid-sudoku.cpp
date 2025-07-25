#include <unordered_set>
#include <vector>

// https://leetcode.com/problems/valid-sudoku/
class Solution {
   public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Hashset is used to query whether a digit repeated or not.
        // I will be quantifying n as both rows and cols (9) for big O.
        // Space complexity should just be O(n) at most.
        unordered_set<char> hash_set;
        int size = board.size();

        // The outer loop scans the graph diagonally.
        // Each inner loop will scan the row and column cells.
        // Time complexity is O(n^2); constants are ignored.
        for (int i = 0; i < size; i++) {
            for (int row = 0; row < size; row++) {
                char cell = board[row][i];
                if (cell == '.') continue;
                if (hash_set.contains(cell)) return false;
                hash_set.insert(cell);
            }
            hash_set.clear();

            for (int col = 0; col < size; col++) {
                char cell = board[i][col];
                if (cell == '.') continue;
                if (hash_set.contains(cell)) return false;
                hash_set.insert(cell);
            }
            hash_set.clear();
        }

        // Scans each sub-boxes (3x3) to check for repetitions.
        // Time complexity is O(n^2) due to only checking each cell once.
        for (int row = 0; row < size; row += 3) {
            for (int col = 0; col < size; col += 3) {
                for (int i = 0; i < size; i++) {
                    char cell = board[row + (i / 3)][col + (i % 3)];
                    if (cell == '.') continue;
                    if (hash_set.contains(cell)) return false;
                    hash_set.insert(cell);
                }
                hash_set.clear();
            }
        }

        return true;
    }
};
