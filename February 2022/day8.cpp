/*
	Add Digits
	https://leetcode.com/problems/add-digits/
*/

// Solution 1:



// Solution 2: Digital Root

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) {
            return 0;
        }
        if(num % 9 == 0) {
            return 9;
        }
        return num % 9;
    }
};