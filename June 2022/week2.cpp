/*
	Minimum Swaps to Group All 1's Together
	https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
*/

// Solution: Sliding Window with Two Pointers

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int zeros = 0, ones = 0;
        for (int x : data) {
            if (x == 1) ones++;
            else    zeros++;
        }
        
        int l = 0, r = 0, cntOnes = 0, maxOnes = 0;
        while (r < data.size()) {
            cntOnes += data[r++];
            if (r - l > ones) {
                cntOnes -= data[l++];
            }
            maxOnes = max(maxOnes, cntOnes);
        }
        
        return ones - maxOnes;
    }
};