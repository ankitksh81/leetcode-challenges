/*
    Product of array except self
    https://leetcode.com/problems/product-of-array-except-self/
*/

// Solution 1: Prefix sum

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n), right(n);
        
        left[0] = nums[0];
        for(int i = 1; i < n; i++) {
            left[i] = left[i-1] * nums[i];
        }
        
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i];
        }
        
        vector<int> ans(n);
        ans[0] = right[1];
        ans[n-1] = left[n-2];
        
        for(int i = 1; i < n-1; i++) {
            ans[i] = left[i-1] * right[i+1];
        }
        
        return ans;
    }
};


// Solution 2: Constant space

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        ans[0] = 1;
        
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        int right = 1;
        for(int i = n-1; i >= 0; i--) {
            ans[i] = right * ans[i];
            right *= nums[i];
        }
        
        return ans;
    }
};