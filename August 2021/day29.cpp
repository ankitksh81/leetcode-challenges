// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3956/


// Solution:

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long res = 1, cnt = 0, i = 0;

        while(res <= n) {
        	if(i < nums.size() && nums[i] <= res) {
        		res += nums[i++];
        	}
        	else {
        		res += res;
        		cnt++;
        	}
        }
        return cnt;
    }
};