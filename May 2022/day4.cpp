/*
	Max Number of K-Sum Pairs
	https://leetcode.com/problems/max-number-of-k-sum-pairs/
*/

// Solution 1: Sorting and Two Pointers

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int l = 0, r = nums.size()-1;
        
        while(l < r) {
            if(nums[l] + nums[r] == k) {
                cnt++;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < k) {
                l++;
            }
            else {
                r--;
            }
        }
        
        return cnt;
    }
};

// Solution 2: Hashmap + Two Pass

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int complement = k - nums[i];
            if (mp[cur] > 0 && mp[complement] > 0) {
                if ((cur == complement) && mp[cur] < 2) {
                    continue;
                }
                mp[cur] = mp[cur] - 1;
                mp[complement] = mp[complement] - 1;
                cnt++;
            }
        }
        
        return cnt;
    }
};

// Solution 3: Hashmap + Single Pass

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int complement = k - nums[i];
            if (mp[complement] > 0) {
                mp[complement] = mp[complement] - 1;
                cnt++;
            }
            else {
                mp[cur]++;
            }
        }
        
        return cnt;
    }
};