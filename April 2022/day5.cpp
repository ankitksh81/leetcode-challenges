/*
	Container With Most Water
	https://leetcode.com/problems/container-with-most-water/
*/

// Solution: Two Pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int l = 0, r = height.size()-1;
        
        while(l < r) {
            ans = max(ans, min(height[r], height[l]) * (r - l));
            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        
        return ans;
    }
};