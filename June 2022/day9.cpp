/*
	Two Sum II - Input Array Is Sorted
	https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

// Solution: Two Pointers

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1;
        
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
            if (numbers[l] + numbers[r] > target) {
                r--;
            }
            else {
                l++;
            }
        }
        
        return {};
    }
};