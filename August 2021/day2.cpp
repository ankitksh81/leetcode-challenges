// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3836/


// Solution:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> umap;
        for(int i = 0; i < n; i++){
            if(umap.find(target-nums[i]) != umap.end()){
                return {umap[target-nums[i]], i};
            }
            else{
                umap[nums[i]] = i;
            }
        }
        return {};
    }
};
