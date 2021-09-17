// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3978/


// Solution 1:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        unordered_map<int, int> m1, m2;
        for(int num: nums1) {
            m1[num]++;
        }
        for(int num: nums2) {
            m2[num]++;
        }
        
        vector<int> ans;
        for(auto it: m1) {
            int val = min(it.second, m2[it.first]);
            for(int i = 0; i < val; i++) {
                ans.push_back(it.first);
            }
        }
        
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        int i = 0, j = 0;
        
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                j++;
            }
            else {
               ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        
        return ans;
    }
};