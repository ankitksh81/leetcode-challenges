/*
        Increasing Tripset Subsequence
        https://leetcode.com/problems/increasing-triplet-subsequence/description/
*/

// Solution: Greedy

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        const int N = nums.size();

        int num1 = INT_MAX, num2 = INT_MAX;

        for (int x : nums) {
            if (x <= num1) {
                num1 = x;
            }
            else if (x <= num2) {
                num2 = x;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
