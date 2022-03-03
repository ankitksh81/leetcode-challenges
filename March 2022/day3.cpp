/*
	Arithmetic Slices
	https://leetcode.com/problems/arithmetic-slices/
*/

// Solution 1: Brute Force with 2 foor loops

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) {
            return 0;
        }
        
        int count = 0;
        for(int s = 0; s < size - 2; s++) {
            int diff = nums[s + 1] - nums[s];
            for(int e = s + 2; e < size; e++) {
                if(nums[e] - nums[e-1] == diff) {
                    count++;
                }
                else
                    break;
            }
        }
        
        return count;
    }
};

// Solution 2: Recursion

class Solution {
public:
    int findSlices(vector<int>& nums, int i, int &sum) {
        if(i < 2) {
            return 0;
        }
        int slices = 0;
        if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
            slices = 1 + findSlices(nums, i-1, sum);
            sum += slices;
        }
        else {
            findSlices(nums, i-1, sum);
        }
        
        return slices;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size(), sum = 0;
        if(size < 3) {
            return 0;
        }
        
        findSlices(nums, size - 1, sum);
        return sum;
    }
};

// Solution 3: Dynamic Programming

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) {
            return 0;
        }
        
        int sum = 0;
        vector<int> dp(size, 0);
        for(int i = 2; i < size; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp[i] = 1 + dp[i-1];
                sum += dp[i];
            }
        }
        
        return sum;
    }
};

// Solution 4: Dynamic Programming with Constant Space

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) {
            return 0;
        }
        
        int sum = 0, dp = 0;
        for(int i = 2; i < size; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                dp = 1 + dp;
                sum += dp;
            }
            else {
                dp = 0;
            }
        }
        
        return sum;
    }
};

// Solution 5: Using Formula

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        if(size < 3) {
            return 0;
        }
        
        int count = 0, sum = 0;
        for(int i = 2; i < size; i++) {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                count++;
            }
            else {
                sum += (count) * (count + 1) / 2;
                count = 0;
            }
        }
        
        return sum += (count) * (count + 1) / 2;
    }
};