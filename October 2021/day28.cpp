/*
    3Sum
    https://leetcode.com/problems/3sum/
*/

// Solution:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            int l = i+1, r = n-1;
            long sum = nums[i];
            while(l < r) {
                if(sum + nums[l] + nums[r] == 0) {
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[l];
                    v[2] = nums[r];
                    ans.push_back(v);
                    
                    while(l < r && nums[l] == v[1]) {
                        l++;
                    }
                    while(r > l && nums[r] == v[2]) {
                        r--;
                    }
                }
                else if(sum + nums[l] + nums[r] > 0) {
                    r--;
                }
                else {
                    l++;
                }
            }
            while(i < n && nums[i] == sum) {
                i++;
            }
            i--;
        }
        
        return ans;
    }
};