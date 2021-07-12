/* Day 12
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3811/
*/

// Solution 1

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sm, tm;
        for(int i = 0; i < s.length(); i++) {
            sm[s[i]] = t[i];
            tm[t[i]] = s[i];
        }
        for(int i = 0; i < s.length(); i++){
            if((tm[t[i]] == s[i] && sm[s[i]] == t[i]))
                continue;
            else
                return false;
        }
        return true;
    }
};


// Solution 2

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, -1), m2(256, -1);
        for(int i = 0; i < s.length(); i++){
            if(m1[s[i]] != m2[t[i]]) {
                return false;
            }
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};
