/*
	Trapping Rain Water
	https://leetcode.com/problems/trapping-rain-water/
*/

// Solution: Two Pointers

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int left_max = INT_MIN, right_max = INT_MIN;
        int l = 0, r = height.size()-1;
        
        while (l < r) {
            if (height[l] < height[r]) {
                left_max = max(left_max, height[l]);
                res += left_max - height[l];
                l++;
            }
            else {
                right_max = max(right_max, height[r]);
                res += right_max - height[r];
                r--;
            }
        }
        
        return res;
    }
};