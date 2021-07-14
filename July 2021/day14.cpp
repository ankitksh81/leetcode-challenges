/* Day 14
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3813/
*/

// Solution 1

class Solution {
public:
    string customSortString(string order, string str)
    {
        unordered_map<char,int> mp;
        int j=0;
        for(auto i:order)
            mp[i]=j++;
        sort(str.begin(),str.end(),[&](const char &a,const char &b){
            return mp[a]<mp[b];
        });
        return str;
    }
};


// Solution 2

class Solution {
public:
    string customSortString(string order, string str) {
        string res = "";
        unordered_map<char, int> m;
        for (char c : str)
            m[c]++;

        for (char c : order) {
            res += string(m[c], c);
            m[c] = 0;
        }
        for (auto a : m) {
            res += string(a.second, a.first);
        }
        return res;
    }
};
