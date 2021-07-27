/* Day 27
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3828/
*/


// Solution 1:

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i = 0; i < n; i++){
            int l = i+1, r = n-1;
            while(l < r){
                int temp = nums[l] + nums[r] + nums[i];

                if(temp == target){
                    return temp;
                }
                else if(abs(temp - target) < diff){
                    ans = temp;
                    diff = abs(temp - target);
                }
                else if(temp > target){
                    r--;
                }
                else if(temp < target){
                    l++;
                }
            }
        }
        return ans;
    }
};


// Solution 2:class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, ans = 0, size = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size; i++) {
            int l = i + 1;
            int h = size - 1;
            
            while(l < h) {
                int sum = nums[i] + nums[l] + nums[h];
                
                if(abs(sum-target) < diff) {
                    ans = sum;
                    diff = abs(sum - target);
                }
                
                if(sum < target)
                    l++;
                else
                    h--;
                
                if(diff == 0)
                    break;
            }
        }
        return ans;
    }
};
