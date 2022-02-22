/*
	Fixed Point
	https://leetcode.com/problems/fixed-point/
*/

// Solution 1: One Pass

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == i) {
                return i;
            }
        }
        
        return -1;
    }
};

// Solution 2: Binary Search

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int size = arr.size();
        int left = 0, right = size - 1, ans = -1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == mid) {
                ans = mid;
                right = mid - 1;
            }
            else if(arr[mid] < mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};