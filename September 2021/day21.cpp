// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3982/


// Solution:

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = INT_MIN, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
            else {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};

