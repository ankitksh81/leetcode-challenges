/*
	Rotate Array
	https://leetcode.com/problems/rotate-array/
*/

// Solution 1: Brute Force

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int temp, previous;
        for(int i = 0; i < k; i++) {
            previous = nums[nums.size()-1];
            for(int j = 0; j < nums.size(); j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
};

// Solution 2: Using extra Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];
        }
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = temp[i];
        }
    }
};

// Solution 3: Cyclic Replacement

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int cnt = 0;
        for(int i = 0; cnt < nums.size(); i++) {
            int cur = i;
            int prev = nums[i];
            do {
                int next = (cur + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                cur = next;
                cnt++;
            } while(i != cur);
        }
    }
};

// Solution 4: Using Reverse

class Solution {
public:
    void reverse(vector<int> & vec, int i, int j){
        while(i<j){
            int t = vec[i];
            vec[i] = vec[j];
            vec[j] = t;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        if(k<0){
            k=k+n;
        }
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};