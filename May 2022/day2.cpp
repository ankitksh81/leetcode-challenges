/*
	Sort Array By Parity
	https://leetcode.com/problems/sort-array-by-parity/
*/

// Solution: Two Pointers

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        while (start <= end) {
            if (nums[start] % 2 == 0) {
                start++;
            }
            else if (nums[end] % 2 != 0) {
                end--;
            }
            
            else if (nums[start] % 2 != 0 && nums[end] % 2 != 0) {
                end--;
            }
            else if (nums[start] % 2 == 0 && nums[end] % 2 == 0) {
                start++;
            }
            else {
                swap(nums[start++], nums[end--]);
            }
        }
        
        return nums;
    }
};