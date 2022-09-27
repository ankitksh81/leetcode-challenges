/*
        Push Dominoes
        https://leetcode.com/problems/push-dominoes/
*/

// Solution 1: Greedy

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
