/*
	Poor Pigs
	https://leetcode.com/problems/poor-pigs/
*/

// Solution: Pigs as Qubit

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest / minutesToDie;
        int x = 0;
        while (pow(T+1, x) < buckets) {
            x++;
        }
        
        return x;
    }
};