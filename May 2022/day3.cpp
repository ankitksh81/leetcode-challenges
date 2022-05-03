/*
	Shortest Unsorted Continuous Subarray
	https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

// Solution 1: Sorting

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        
        int l = 0, r = n-1;
        while (l < n && nums[l] == temp[l]) {
            l++;
        }
        
        while (r >= 0 && nums[r] == temp[r]) {
            r--;
        }
        
        return (l == n ? 0 : (r - l + 1));
    }
};

// Solution 2: Monotonic Stack

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = n, r = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty())  st.pop();
        
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() &&  nums[st.top()] < nums[i]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        return (r - l > 0 ? r - l + 1 : 0);
    }
};