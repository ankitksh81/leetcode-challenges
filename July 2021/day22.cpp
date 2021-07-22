/* Day 22
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3823/
*/


// Solution 1:

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), minVal = nums[n - 1];
        vector <int> mx(n);
        mx[0] = nums[0];
        for(int i = 1; i < n; i++) {
            mx[i] = max(nums[i], mx[i - 1]);
        }
        int ans = n - 1;
        for(int i = n - 1; i >= 1; i--) {
            minVal = min(minVal, nums[i]);
            if(minVal >= mx[i - 1]) {
                ans = i;
            }
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size();
        vector<int> mx(n), mi(n);
        mx[0] = A[0];
        mi[n-1] = A[n-1];

        for(int i = 1; i < n; i++) {
            mx[i] = max(A[i], mx[i-1]);
        }
        for(int i = n-2; i >= 0; i--) {
            mi[i] = min(A[i], mi[i+1]);
        }
        int i;
        for(i = 0; i < n-1; i++) {
            if(mx[i] <= mi[i+1])
                break;
        }
        return i+1;
    }
};
