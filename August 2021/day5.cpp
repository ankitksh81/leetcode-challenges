// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3870/


// Solution 1:

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int n = piles.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for(int i = 0; i < n; i++) {
			dp[i][i] = piles[i];
		}

		for(int d = 1; d < n; d++) {
			for(int i = 0; i < n - d; i++) {
				dp[i][i+d] = max(piles[i] - dp[i+1][i+d], piles[i][i+d-1]);
			}
		}
		return dp[0][n-1] > 0;
	}
};


// Solution 2:

class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		vector<int> dp = piles;
		for(int d = 1; d < piles.size(); d++) {
			for(int i = 0; i < piles.size() - d; i++) {
				dp[i] = max(piles[i] - dp[i + 1], piles[i + d] - dp[i]);
			}
		}
		return dp[0] > 0;
	}
};