/*
        Largest Perimeter Triangle
        https://leetcode.com/problems/largest-perimeter-triangle/description/
*/

// Solution: Sorting + Greedy

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        

        for (int i = N-3; i >= 0; i--) {
            if (nums[i] + nums[i+1] > nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return 0;
    }
};
