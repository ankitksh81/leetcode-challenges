/*
        3Sum Closest
        https://leetcode.com/problems/3sum-closest/description/
*/

// Solution: Two Pointers

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        int sum = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n-1;
            
            while (l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if (diff > abs(curSum - target)) {
                    diff = abs(curSum - target);
                    sum = curSum;
                }
                
                if (curSum < target) {
                    l++;
                }
                else if(curSum > target) {
                    r--;
                }
                
                if(diff == 0) {
                    return sum;
                }
            }
        }
        
        return sum;
    }
};
