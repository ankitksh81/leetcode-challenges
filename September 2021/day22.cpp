// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3984/


// Solution 1:

class Solution {
public:
    int dfs(vector<string>& arr, string res, int pos) {
        unordered_set<char> s(res.begin(), res.end());
        if(res.size() != s.size()) {
            return 0;
        }
        
        int best = res.size();
        for(int i = pos; i < arr.size(); i++) {
            best = max(best, dfs(arr, res + arr[i], i+1));
        }
        
        return best;
    }
    
    int maxLength(vector<string>& arr) {
        return dfs(arr, "", 0);
    }
};


// Solution 2:

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            int n = arr[i].size();
            bitset<26> bs;
            for(char c: arr[i]) {
                bs.set(c - 'a');
            }
            if(bs.count() < n) {
                continue;
            }
            for(int j = dp.size() - 1; j >= 0; j--) {
                bitset x = dp[j];
                if((x & bs).any()) {
                    continue;
                }
                // a=x|bs;
                dp.push_back(x | bs);
                res = max(res, int(x.count()) + n);
            }
                
        }
        return res;
    }
};