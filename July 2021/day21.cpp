/* Day 21
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3821/
*/


// Solution 1:

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> ltr(n), rtl(n);
        int l = 0;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'R') {
                l = 1;
                ltr[i] = l;
            }
            else if(dominoes[i] == '.' && l >= 1) {
                l++;
                ltr[i] = l;
            }
            else {
                l = 0;
            }
        }
        l = 0;
        for(int i = n-1; i >= 0; i--) {
            if(dominoes[i] == 'L') {
                l = 1;
                rtl[i] = l;
            }
            else if(dominoes[i] == '.' && l >= 1) {
                l++;
                rtl[i] = l;
            }
            else {
                l = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            if(ltr[i] == rtl[i]) {
                continue;
            }
            else if(ltr[i] < rtl[i]) {
                if(ltr[i] == 0)
                    dominoes[i] = 'L';
                else
                    dominoes[i] = 'R';
            }
            else {
                if(rtl[i] == 0)
                    dominoes[i] = 'R';
                else
                    dominoes[i] = 'L';
            }
        }
        return dominoes;
    }
};


// Solution 2:

class Solution {
public:
    string pushDominoes(string dominoes) {
        char prev = 'L';
        int l = -1, curr = 0, n = dominoes.length();
        while (curr < n) {
            if (dominoes[curr] == '.') {
                curr++;
            } else {
                if (dominoes[curr] == 'R') {
                    if (prev == 'R') {
                        for (int i = l+1; i < curr; i++)
                            dominoes[i] = 'R';
                    }
                    prev = 'R';
                    l = curr;
                } else {
                    if (prev == 'L') {
                        for (int i = l+1; i < curr; ++i)
                            dominoes[i] = 'L';
                    } else {
                        int f = l+1, s = curr-1;
                        while (f < s) {
                            dominoes[f++] = 'R';
                            dominoes[s--] = 'L';
                        }
                    }
                    prev = 'L';
                    l = curr;
                }
                curr++;
            }
        }
        if (prev == 'R') {
            for (int i = l+1; i < n; i++) dominoes[i] = 'R';
        }
        return dominoes;
    }
};
