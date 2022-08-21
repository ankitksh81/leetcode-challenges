/*
	Stamping The Sequence
	https://leetcode.com/problems/stamping-the-sequence/
*/

// Solution: Greedy

class Solution {
    vector<int> res;
    int stars, n, m;
public:
    bool checkAndReplace(string &target, int &start, string &stamp) {
        for (int i = 0; i < m; i++) {
            if (target[i + start] != '*' && target[i + start] != stamp[i]) {
                return false;
            }
        }
        
        res.push_back(start);
        for (int i = start; i - start < m; i++) {
            stars += (target[i] != '*');
            target[i] = '*';
        }
        
        return true;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        stars = 0, n = target.size(), m = stamp.size();
        vector<bool> vis(n, false);
        while (stars < n) {
            bool replaced = false;
            for (int i = 0; i <= n-m && stars < n; i++) {
                if (!vis[i]) {
                    replaced = checkAndReplace(target, i, stamp);
                    vis[i] = replaced;
                }
            }
            if (!replaced) return {};
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};