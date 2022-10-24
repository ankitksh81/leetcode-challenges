/*
        Maximum Length of a Concatenated String with Unique Characters
        https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
*/

// Solution 1: Backtracking

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


// Solution 2: Dynamic Programming + Bitset

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp = { bitset<26>() };
        int res = 0;

        for (string &s : arr) {
            int N = s.length();
            bitset<26> bs;

            for (char c : s) {
                bs.set(c - 'a');
            }

            if (bs.count() < N) continue;

            for (int i = dp.size() - 1; i >= 0; i--) {
                bitset x = dp[i];
                if ((x & bs).any()) continue;

                dp.push_back(x | bs);
                res = max(res, int(x.count()) + N);
            }
        }

        return res;
    }
};
