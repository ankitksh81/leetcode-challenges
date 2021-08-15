// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3891/


// Solution 1:

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c: t) {
            mp[c]++;
        }

        int dist = mp.size();
        unordered_map<char, int> window;
        int count = 0, ll = 0, rr = 0;
        int l = 0, r = 0, ans = INT_MAX;

        while(r < s.length()) {
            window[s[r]]++;

            if(mp.count(s[r]) and mp[s[r]] == window[s[r]]) {
                count++;
            }
            r++;

            while(count == dist and l < r) {
                if(ans > r - l) {
                    ans = r - l;
                    ll = l;
                    rr = r;
                }

                window[s[l]]--;
                if(mp.count(s[l]) and window[s[l]] < mp[s[l]]) {
                    count--;
                }
                l++;
            }
        }
        return s.substr(ll, rr-ll);
    }
};


// Solution 2:

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0)
            return "";
        vector<int> remaining(128, 0);
        int required = t.size();
        for(int i = 0; i < required; i++) {
            remaining[t[i]]++;
        }
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if(i == s.size()){
                    break;
                }
                remaining[s[i]]--;
                if(remaining[s[i]] >= 0) {
                    required--;
                }
                i++;
            }
            else {
                if(i - start < min) {
                    min = i -start;
                    left = start;
                }
                remaining[s[start]]++;
                if(remaining[s[start]] > 0) {
                    required++;
                }
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};