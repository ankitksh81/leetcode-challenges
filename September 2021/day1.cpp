// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3960/


// Solution 1:

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int maxlen = 0;
		for(int i = 0; i < nums.size(); i++) {
			int size = 0;
			for(int j = i; nums[j] >= 0; size++) {
				int val = nums[j];
				nums[j] = -1;
				j = val;
			}
			maxlen = max(maxlen, size);
		}
		return maxlen;
	}
};


// Solution 2:

class Solution {
public:
	int n;
	vector<int> vis;

	int helper(vector<int>& nums, int i) {
		if(vis[i] == 1) {
			return 0;
		}
		vis[i] = 1;
		return 1 + helper(nums, nums[i]);
	}

	int arrayNesting(vector<int>& nums) {
		int ans = 0;
		n = nums.size();
		vis = vector<int>(n, 0);

		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				ans = max(ans, helper(nums, i));
			}
		}

		return ans;
	}
};