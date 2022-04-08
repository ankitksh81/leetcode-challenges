/*
	Minimize Product Sum of Two Arrays
	https://leetcode.com/problems/minimize-product-sum-of-two-arrays/
*/

// Solution 1: Sorting

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        
        sort(nums1.rbegin(), nums1.rend());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); i++) {
            ans += nums1[i] * nums2[i];
        }
        
        return ans;
    }
};

// Solution 2: Counting Sort

class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> count1(101), count2(101);
        int sum = 0;
        
        for(int x : nums1) {
            count1[x]++;
        }
        for(int x : nums2) {
            count2[x]++;
        }
        
        int p1 = 1, p2 = 100;
        while(p1 < 101 && p2 > 0) {
            while(p1 < 101 && count1[p1] == 0) {
                p1++;
            }
            while(p2 > 0 && count2[p2] == 0) {
                p2--;
            }
            
            if(p1 == 0 || p2 == 0) {
                break;
            }
            
            int val = min(count1[p1], count2[p2]);
            sum += val * p1 * p2;
            count1[p1] -= val;
            count2[p2] -= val;
        }
        
        return sum;
    }
};