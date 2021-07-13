/* Day 13
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3812/
*/

// Solution 1

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        if(n == 1){
            return ans;
        }
        for(int i = 1; i < n; i++) {
            if(i == 1){
                if(nums[i] < nums[0]){
                    return 0;
                }
            }
            if(i == n-1){
                if(nums[i] > nums[i-1]){
                    return i;
                }
            }
            if(nums[i-1] < nums[i] and nums[i] > nums[i+1]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};


// Solution 2

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return l;
    }
};
