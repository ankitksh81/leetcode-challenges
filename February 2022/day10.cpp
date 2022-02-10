/*
	Subarray Sum Equals K
	https://leetcode.com/problems/subarray-sum-equals-k/
*/

// Solution: Hashmaps

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, sum = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(umap.find(sum - k) != umap.end()) {
                cnt += umap[sum - k];
            }
            umap[sum]++;
        }
        return cnt;
    }
};