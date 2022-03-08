/*
	Strobogrammatic Number II
	https://leetcode.com/problems/strobogrammatic-number-ii/
*/

// Solution: Recursion

class Solution {
public:
    vector<vector<char>> reversiblePairs = {
        {'0', '0'}, {'1', '1'}, 
        {'6', '9'}, {'8', '8'}, {'9', '6'}
    };

    vector<string> generateNumbers(int n, int finalLength) {
        if(n == 0) {
            return {""};
        }

        if(n == 1) {
            return {"0", "1", "8"};
        }

        vector<string> prevNums = generateNumbers(n - 2, finalLength);
        vector<string> curNums;

        for(string &prev : prevNums) {
            for(vector<char> &pair : reversiblePairs) {
                if(pair[0] != '0' || n != finalLength) {
                    curNums.push_back(pair[0] + prev + pair[1]);
                }
            }
        }

        return curNums;
    }
    
    vector<string> findStrobogrammatic(int n) {
        return generateNumbers(n, n);
    }
};