/*
	Valid Mountain Array
	https://leetcode.com/problems/valid-mountain-array/
*/

// Solution 1: One Pass

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), idx = 0;
        int prev = arr[0];
        // check for increasing
        while(idx + 1 < n && arr[idx] < arr[idx+1]) {
            idx++;
        }
        
        if(idx == 0 || idx == n-1) {
            return false;
        }
        
        // check for decreasing
        while(idx + 1 < n && arr[idx] > arr[idx+1]) {
            idx++;
        }
        
        return idx == n-1;
    }
};