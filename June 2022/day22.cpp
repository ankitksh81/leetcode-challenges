/*
	Kth Largest Element in an Array
	https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

// Solution 1: Min Heap

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < N; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        return pq.top();
    }
};


// Solution 2: Quick Select

class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; j++) {
            if (nums[j] >= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return (i+1);
    }
    
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivot = partition(nums, l, r);
        if (pivot == k-1)   return nums[pivot];
        if (pivot > k-1) {
            return quickSelect(nums, l, pivot - 1, k);
        }
        else {
            return quickSelect(nums, pivot + 1, r, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int N = nums.size();
        return quickSelect(nums, 0, N-1, k);
    }
};