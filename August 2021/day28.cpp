// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3950/


// Solution 1:

class Solution {
	struct interval {
		int st, en, profit;
	};
	vector<interval> nums;
	vector<int> dp;

	int getlowerBound(int idx) {
		int low = idx + 1;
		int high = size(nums)-1;
		int ans = -1;
		while(low <= high) {
			int mid = low + (high - low) / 2;
			if(nums[mid].st >= nums[idx].en) {
				ans = mid;
				high = mid-1;
			}
			else {
				low = mid + 1;
			}
		}
		return ans;
	}

	int getMaxProfit(int idx = 0) {
		if(idx >= size(nums))
			return 0;

		if(dp[idx] != -1) {
			return dp[idx];
		}
		int nextElementIdx = getlowerBound(idx);
		int include = nums[idx].profit + (nextElementIdx == -1 ? 0 : getMaxProfit(nextElementIdx));
		int exclude = getMaxProfit(idx + 1);

		return dp[idx] = max(exclude, include);
	}

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        nums.resize(n);
        dp.resize(n+1, -1);

        for(int i = 0; i < n; i++) {
        	nums[i].st = startTime[i];
        	nums[i].en = endTime[i];
        	nums[i].profit = profit[i];
        }

        sort(nums.begin(), nums.end(), [&](struct interval a, struct interval b){
        	return a.st < b.st;
        });

        return getMaxProfit();
    }
};


// Solution 2:

class Job{
public:
    int start, finish, profit;
};

bool cmp(Job a, Job b){
    return a.finish < b.finish;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        Job vec[n];
        
        for(int i = 0; i < n; i++) {
            vec[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(vec, vec + n, cmp);
        
        int dp[n];
        dp[0] = vec[0].profit;
        
        for(int i = 1; i < n; i++) {
            int include = vec[i].profit;
            int last = -1;
            
            for(int j = i - 1; j >= 0; j--) {
                if(vec[j].finish <= vec[i].start) {
                    last = j;
                    break;
                }
            }
            
            if(last != -1) {
                include += dp[last];
            }
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        
        return dp[n - 1];
    }
};