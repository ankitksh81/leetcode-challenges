/*
    Maximum product subarray
    https://leetcode.com/problems/maximum-product-subarray/
*/

// Solution: DP

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        
        int cur_max = nums[0];
        int cur_min = nums[0];
        int max_prod = cur_max;
        
        for(int i = 1; i < nums.size(); i++) {
            int cur = nums[i];
            int temp_mx = max(cur, max(cur_max * cur, cur_min * cur));
            cur_min = min(cur, min(cur_max * cur, cur_min * cur));
            
            cur_max = temp_mx;
            max_prod = max(cur_max, max_prod);
        }
        
        return max_prod;
    }
};