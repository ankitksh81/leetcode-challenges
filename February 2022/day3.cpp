/*
	4Sum II
	https://leetcode.com/problems/4sum-ii/
*/

// Solution: Hashmap

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int ans = 0;
        unordered_map<int, int> ump;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ump[nums1[i] + nums2[j]]++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(ump.find(0 - nums3[i] - nums4[j]) != ump.end()) {
                    ans += ump[0 - nums3[i] - nums4[j]];
                }
            }
        }
        
        return ans;
    }
};