/*
	Contiguous Array
	https://leetcode.com/problems/contiguous-array/
*/

// Solution 1: Using Hashmap

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> umap; // <index, count>
        umap[0] = -1;
        int maxlen = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt = cnt + (nums[i] == 1 ? 1 : -1);
            if(umap.find(cnt) != umap.end()) {
                maxlen = max(maxlen, i - umap[cnt]);
            }
            else {
                umap[cnt] = i;
            }
        }
        return maxlen;
    }
};