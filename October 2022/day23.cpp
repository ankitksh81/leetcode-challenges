/*
	Set Mismatch
	https://leetcode.com/problems/set-mismatch/description/
*/

// Solution 1: Counting

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int ar[10005] = {0};
        int dup, mis;
        for(int i = 0; i < nums.size(); i++){
            ar[nums[i]]++;
        }
        for(int i = 1; i <= nums.size(); i++){
            if(ar[i] == 0){
                mis = i;
            }
            if(ar[i] == 2){
                dup = i;
            }
        }
        return {dup, mis};
    }
};