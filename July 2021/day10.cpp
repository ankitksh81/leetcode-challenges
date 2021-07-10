/* Day 10
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3809/
*/

// Solution 1

class Solution {
    int MOD = 1e9+7;
public:
    int numDecodings(string s) {
        long long first = 1, second = (s[0] == '*' ? 9 : s[0] == '0' ? 0 : 1);

        for(int i = 1; i < s.length(); i++) {
            long long temp = second;

            if(s[i] == '*') {
                second = 9 * second % MOD;

                if(s[i-1] == '1') {
                    second = (second + 9 * first) % MOD;
                }
                else if(s[i-1] == '2') {
                    second = (second + 6 * first) % MOD;
                }
                else if(s[i-1] == '*') {
                    second = (second + 15 * first) % MOD;
                }

            }
            else {
                second = (s[i] != '0' ? second : 0);

                if(s[i-1] == '1') {
                    second = (second + first) % MOD;
                }
                else if(s[i-1] == '2' && s[i] <= '6') {
                    second = (second + first) % MOD;
                }
                else if(s[i-1] == '*') {
                    second = (second + (s[i] <= '6' ? 2 : 1) * first) % MOD;
                }
            }
            first = temp;
        }
        return (int)second;
    }
};


// Solution 2

#define mod 1000000007

class Solution {
public:
    int oneDigit(char a){
        // a: current character
        if (a == '*')
            return 9;
        else if(a >= '1')
            return 1;
        return 0;
    }

    int twoDigit(char b, char a){
        // a: current character and b: last character
        if (b == '*'){
            if (a == '*')
                return 15;
            else
                return (a >= '0' && a <= '6') ? 2 : 1;
        }
        else if (b == '1')
            return a == '*' ? 9 : 1;
        else if (b == '2') {
            if (a == '*')
                return 6;
            else
                return (a >= '0' && a <= '6') ? 1 : 0;
        }
        return 0;
    }

    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // To store number of permutations;
        long long int prev2, prev1, curr;
        if (s[0] == '0')
            return 0;

        int n = s.size();
        prev1 = s[0] == '*' ? 9 : 1;
        curr = prev1;
        prev2 = 1;

        for (int i = 1; i < n; i++){
            curr = ((prev1 * oneDigit(s[i])) + (prev2 * twoDigit(s[i-1], s[i]))) % mod;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

