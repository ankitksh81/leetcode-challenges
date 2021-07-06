/* Day 1
    Problem link : https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3799/
*/

// Solution:

class Solution{
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i = 0; i < (1 << n); i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;
    }
};
