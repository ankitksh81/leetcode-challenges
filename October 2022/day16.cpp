/*
	Minimum Difficulty of a Job Schedule
	https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
*/

// Solution: Recursion + Memoization

class Solution {
    int N;
    // dp[jobs][days]
    int dp[305][15];
public:
    int getMinDifficulty(vector<int>& diff, int job, int days) {
        // if all jobs done and no more days left -> difficulty = 0
        if (job == N && days == 0) return 0;

        // if all jobs done or no more days left or
        // more days than jobs left -> difficulty = INF;
        if (job == N || days == 0 || N - job < days) return 1e8;

        if (dp[job][days] != -1) return dp[job][days];

        long minDifficulty = 1e8, curMaxDifficulty = 0;

        for (int j = job; j < N; j++) {
            // current Max difficulty
            curMaxDifficulty = max(curMaxDifficulty, (long)diff[j]);
            // minDifficulty = min of minDiff till now & curMaxDiff +
            // minDiff from all the remaining jobs done next day onwards 
            minDifficulty = min(minDifficulty, 
                    curMaxDifficulty + getMinDifficulty(diff, j+1, days-1));
        }

        return dp[job][days] = minDifficulty;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        N = jobDifficulty.size();
        if (N < d) return -1;

        memset(dp, -1, sizeof(dp));
        return getMinDifficulty(jobDifficulty, 0, d);
    }
};