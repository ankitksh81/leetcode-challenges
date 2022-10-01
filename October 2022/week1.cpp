/*
	Lonely Pixel I
	https://leetcode.com/problems/lonely-pixel-i/description/
*/

// Solution: Greedy

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int M = picture.size(), N = picture[0].size();
        vector<int> rows(M), col(N);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (picture[i][j] == 'B') {
                    rows[i]++;
                    col[j]++;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (picture[i][j] == 'B') {
                    if (rows[i] == 1 && col[j] == 1) {
                        result++;
                    } 
                }
            }
        }

        return result;
    }
};