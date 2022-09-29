/*
    Find K Closest Element
    https://leetcode.com/problems/find-k-closest-elements/
*/

// Solution: Binary Search

class Solution {
public:
    int getLeftMostIndex(vector<int>& arr, int k, int x) {
        int l = 0, h = arr.size()-k;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(x - arr[mid] > arr[mid + k] - x) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        
        return l;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = getLeftMostIndex(arr, k, x);
        vector<int> res;
        for(int i = left; i < left + k; i++) {
            res.push_back(arr[i]);
        }
        
        return res;
    }
};
