/*
	Longest Consecutive Sequence
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

// Solution 1: Sorting

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 1, cnt = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                if (nums[i] == nums[i-1] + 1) {
                    cnt++;
                }
                else {
                    res = max(res, cnt);
                    cnt = 1;
                }
            }
        }
        
        return max(res, cnt);
    }
};


// Solution 2: Hashset

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int &x: nums) 
            st.insert(x);
        
        int res = 0;
        for(auto x : st) {
            if(st.find(x-1) == st.end()) {
                int cur = x;
                int len = 1;
                
                while(st.find(cur + 1) != st.end()) {
                    cur++;
                    len++;
                }
                
                res = max(res, len);
            }
        }
        
        return res;
    }
};