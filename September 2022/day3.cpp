/*
	Numbers With Same Consecutive Differences
	https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/

// Solution 1: Backtracking

class Solution {
    vector<int> res;
public:
    void solve(int n, int k, int num, int len) {
        if (len == n) {
            res.push_back(num);
            return;
        }
        
        int rem = num % 10;
        if (rem + k <= 9) {
            solve(n, k, num * 10 + (rem + k), len + 1);
        }
        if (k != 0 && rem - k >= 0) {
            solve(n, k, num * 10 + (rem - k), len + 1);
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int digit = 1; digit <= 9; digit++) {
            solve(n, k, digit, 1);
        }
        return res;
    }
};


// Solution 2: BFS

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= n; i++) {
            vector<int> cur;
            for (int x : res) {
                int rem = x % 10;
                if (rem + k < 10) {
                    cur.push_back(x * 10 + rem + k);
                }
                if (k > 0 && rem - k >= 0) {
                    cur.push_back(x * 10 + rem - k);
                }
            }
            
            res = cur;
        }
        
        return res;
    }
};