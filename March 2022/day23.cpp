/*
	Broken Calculator
	https://leetcode.com/problems/broken-calculator/
*/

// Solution: Greedy Backwards

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int steps = 0;
        while (target > startValue) {
            steps++;
            if(target & 1) {
                target++;
            }
            else {
                target /= 2;
            }
        }
        
        return steps + startValue - target;
    }
};