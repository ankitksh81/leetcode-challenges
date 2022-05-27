/*
	Number of Steps to Reduce a Number to Zero
	https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
*/

// Solution:

class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num != 0) {
            if (num & 1) {
                num -= 1;
            }
            else {
                num /= 2;
            }
            cnt++;
        }
        
        return cnt;
    }
};