/*
	Integer to Roman
	https://leetcode.com/problems/integer-to-roman/description/
*/

// Solution: 

class Solution {
public:
    string intToRoman(int num) {
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> thousands = {"", "M", "MM", "MMM"};
        
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[(num % 10)];
    }
};