/*
        Sum of Even Numbers After Queries
        https://leetcode.com/problems/sum-of-even-numbers-after-queries/
*/

// Solution:

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        
        for (int num : nums) {
            if (num % 2 == 0) sum += num;
        }
        
        vector<int> res;
        for (vector<int>& query : queries) {
            int val = query[0], idx = query[1];
            
            if (nums[idx] % 2 == 0) {
                sum -= nums[idx];
            }
            nums[idx] += val;
            if (nums[idx] % 2 == 0) {
                sum += nums[idx];
            }
            
            res.push_back(sum);
        }
        
        return res;
    }
};
