// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/640/week-5-september-29th-september-30th/3993/


// Solution 1:

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k) {
            return false;
        }
        vector<bool> dp(1 << n);
        vector<int> total(1 << n);
        dp[0] = true;
        
        sort(nums.begin(), nums.end());
        sum /= k;
        if(nums[n-1] > sum){
            return false;
        }
        
        for(int i = 0; i < (1 << n); i++) {
            if(dp[i]) {
                for(int j = 0; j < n; j++) {
                    int temp = i | (1 << j);
                    if(temp != i) {
                        if(nums[j] <= (sum - (total[i] % sum))) {
                            dp[temp] = true;
                            total[temp] = nums[j] + total[i];
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};


// Solution 2:

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = 0;
        for(auto x : nums) {
            total_sum += x;
        }
        
        int partitions_sum = total_sum / k;
        
        if(k == 0 || total_sum % k != 0)
            return false;
        
        vector<bool> seen(nums.size(),false);
        
        return generate_partitions(nums,partitions_sum,0,0,k,seen);
    }
    
    
    bool generate_partitions(vector<int>& nums, int partitions_sum, int curr_sum,
                             int index, int k, vector<bool> &seen) {
        if(k == 1) {
            return true;
        }
        if(curr_sum > partitions_sum)
            return false;
        
        if(partitions_sum == curr_sum) {
            return generate_partitions(nums, partitions_sum, 0, 0, k - 1, seen);
        }
        
        for(int i = index; i < nums.size(); i++) {
            if(!seen[i]) {
                seen[i] = true;
                if(generate_partitions(nums, partitions_sum, curr_sum + nums[i], i + 1, k, seen))
                    return true;
                seen[i] = false;
            }
        }
        return false;
    }
};