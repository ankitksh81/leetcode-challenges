/* Day 28
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3829/
*/


// Solution 1:

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        sort(ans.begin(), ans.end(), [](auto &x, auto &y){
            return -(x^y)&x&~y;
        });
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while(res.size() < N) {
            vector<int> tmp;
            for(int i : res) {
                if(i * 2 - 1 <= N)
                    tmp.push_back(i * 2 - 1);
            }
            for(int i : res) {
                if(i * 2 <= N)
                    tmp.push_back(i * 2);
            }
            res = tmp;
        }
        return res;
    }
};
