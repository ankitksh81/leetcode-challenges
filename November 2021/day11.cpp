/*
    Minimum value to get positive step by step sum
    https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
*/

// Solution 1: Using prefix sum 

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int val = 1 - nums[0];
        int ans = max(1, val);
        
        for(int i = 1; i < nums.size(); i++) {
            val = val - nums[i];
            ans = max(ans, val);
        }
        
        return ans;
    }
};

// Solution 2: Using binary search

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int m = 100;
        int l = 1, r = m * n + 1;
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            int total = mid;
            bool isValid = true;
            
            for(int num: nums) {
                total += num;
                if(total < 1) {
                    isValid = false;
                    break;
                }
            }
            
            if(isValid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};