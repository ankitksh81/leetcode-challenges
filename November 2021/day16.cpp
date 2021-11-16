/*
    Kth smallest number in multiplication table
    https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
*/

// Solution: Binary search

class Solution {
public:
    bool enough(int x, int m, int n, int k) {
        int count = 0;
        for(int i = 1; i <= m; i++) {
            count += min(x / i, n);
        }
        
        return count >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 0, h = m * n;
        while(l < h) {
            int mid = l + (h - l) / 2;
            if(!enough(mid, m, n, k)) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        
        return l;
    }
};