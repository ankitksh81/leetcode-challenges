/*
	Split Array Largest Sum
	https://leetcode.com/problems/split-array-largest-sum/
*/

// Solution: Binary Search

class Solution {
public:
    bool canDo(vector<int>& nums, int cuts, long long max) {
        int sum = 0;
        for(int num : nums) {
            if(sum + num <= max) {
                sum += num;
            }
            else {
                cuts--;
                sum = num;
                
                if(cuts < 0) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }
        
        while(left < right) {
            long long mid = left + (right - left) / 2;
            if(canDo(nums, m-1, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};