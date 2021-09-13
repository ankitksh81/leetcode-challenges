// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3973/


// Solution 1:

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = (int)text.length();
        if(n < 6) {
            return 0;
        }
        unordered_map<char, int> m;
        unordered_set<char> s{'b', 'a', 'l', 'o', 'n'};
        m.insert({'b', 0});
        m.insert({'a', 0});
        m.insert({'l', 0});
        m.insert({'o', 0});
        m.insert({'n', 0});
        
        for(char c: text) {
            if(s.count(c)){
                m[c]++;
            }
        }
        
        m['l'] = m['l'] / 2;
        m['o'] = m['o'] / 2;
        
        int ans = INT_MAX;
        for(auto it: m) {
            ans = min(ans, it.second);
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int f[26];
        memset(f, 0, sizeof(f));
        for(char c: text) {
            f[c - 'a']++;
        }
        int minn = INT_MAX;
        minn = min(minn, f['b' - 'a']);
        minn = min(minn, f['a' - 'a']);
        minn = min(minn, f['n' - 'a']);
        minn = min(minn, f['l' - 'a'] / 2);
        minn = min(minn, f['o' - 'a'] / 2);
        return minn;
    }
};