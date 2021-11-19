/*
    Hamming Distance
    https://leetcode.com/problems/hamming-distance/
*/

// Solution:

class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist = 0;
        for(int i = 31; i >= 0; i--) {
            if((x & (1 << i)) != (y & (1 << i))) {
                dist++;
            }
        }
        return dist;
    }
};
