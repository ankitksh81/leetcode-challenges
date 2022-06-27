/*
	Partitioning Into Minimum Number Of Deci-Binary Numbers
	https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
*/

// Solution: Greedy

class Solution {
public:
    int minPartitions(string n) {
        int res = 0, N = n.length();
        for (char c : n) {
            res = max(res, c - '0');
        }
        
        return res;
    }
};