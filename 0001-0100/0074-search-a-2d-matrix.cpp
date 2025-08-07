#include <vector>

// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
   public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        // Since this is a 2D array, calculations are a bit more complex.
        // Space complexity is O(1); only stores fixed sized pointers.
        int left = 0;
        int right = ((matrix.size()) * (matrix[0].size())) - 1;

        // This is a standard binary search algorithm.
        // Calculations are made to pinpoint the col and row of the pointer.
        // Time complexity is O(log(m * n)); m = row, n = col, vice versa.
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            int i = mid / matrix[0].size();
            int j = mid % matrix[0].size();

            if (matrix[i][j] == target) return true;
            matrix[i][j] < target ? left = mid + 1 : right = mid - 1;
        }

        return false;
    }
};
