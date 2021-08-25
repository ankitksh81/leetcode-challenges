// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3918/


// Solution:

class Solution {
public:         
    bool judgeSquareSum(int c) {
        long long num = 0;
        for(long long i = 0; i * i <= c; i++) {
            num = sqrt(c - i * i);
            if(num * num == c - i * i){
                return true;
            }
        }
        return false;
    }
};
