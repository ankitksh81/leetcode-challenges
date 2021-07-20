/* Day 20
    Problem lin: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3820/
*/


// Solution 1:

class Solution {
    vector<int> copy, ans;
public:
    Solution(vector<int>& nums) {
        copy = nums;
        ans = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        ans = copy;
        return ans;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(ans.begin(), ans.end());
        return ans;
    }
};


// Solution 2:

class Solution {
    vector<int> v, p;
    std::mt19937 g;
public:
    Solution(vector<int>& nums) {
        v = nums;
        p.resize(v.size());
        iota(p.begin(), p.end(), 0);
        random_device rd;
        g.seed(rd());
    }

    vector<int> reset() {
        return v;
    }

    vector<int> shuffle() {
        std::shuffle(p.begin(), p.end(), g);
        vector<int> s(v.size());
        for(int i = 0; i < v.size(); i ++)
            s[i] = v[p[i]];
        return s;
    }
};
