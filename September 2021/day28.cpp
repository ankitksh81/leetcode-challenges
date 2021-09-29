// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3990/


// Solution 1:
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v(2);
        for(int x: nums) {
            if(x & 1) {
                v[1].push_back(x);
            }
            else {
                v[0].push_back(x);
            }
        }

        int l = 0, r = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                nums[i] = v[1][r++];
            }
            else {
                nums[i] = v[0][l++];
            }
        }
        
        return nums;
    }
};


// Solution 2:

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1, n = nums.size();
        while(i < n && j < n) {
            if(nums[i] % 2 == 0) {
                i += 2;
            }
            else if(nums[j] % 2 != 0) {
                j += 2;
            }
            else {
                swap(nums[i], nums[j]);
                i += 2;
                j += 2;
            }
        }
        return nums;
    }
};