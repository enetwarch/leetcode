#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int highest = 0;
        while (l < r) {
            int area = calculateArea(height, l, r);
            highest = area > highest ? area : highest;

            height[l] > height[r] ? r-- : l++;
        }

        return highest;
    }

   private:
    int calculateArea(std::vector<int>& height, int l, int r) {
        int smaller = height[l] < height[r] ? height[l] : height[r];
        return smaller * (r - l);
    }
};
