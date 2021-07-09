/* Day 9
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3808/
*/

// Solution 1

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1);
        fill(dp.begin(), dp.end(), 1);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(nums[j] > nums[i]) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};


// Solution 2

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> v;

        for(int i = 0; i < n; i++) {
            if(v.size() == 0 || v.back() < nums[i]) {
                v.push_back(nums[i]);
                continue;
            }

            ans = max(ans, (int)v.size());
            int l = 0, h = v.size() - 1, idx = -1;
            while(l <= h){
                int mid = (l + h) / 2;
                if(v[mid] >= nums[i]){
                    idx = mid;
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            if(idx != -1) {
                v[idx] = nums[i];
            }
        }
        return (int)v.size();
    }
};
