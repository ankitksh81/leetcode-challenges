// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3907/


// Solution 1:

const int MOD = (int)1e9+7;
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> ys;
        for(auto const &r: rectangles) {
            ys.insert(r[1]);
            ys.insert(r[3]);
        }

        sort(rectangles.begin(), rectangles.end(), [](auto const &r1, auto const &r2){
            return r1[0] < r2[0];
        });

        int prev_y = *ys.begin();
        long long res = 0;

        for(auto y: ys) {
            long long height = y - prev_y;
            long long x_start = rectangles.front()[0];
            long long x_end = x_start;

            for(auto const &r: rectangles) {
                if(r[1] <= prev_y && r[3] >= y) {
                    if(r[0] > x_end) {
                        res += height * (x_end - x_start) % MOD;
                        x_start = r[0];
                    }
                    if(r[2] > x_end) {
                        x_end = r[2];
                    }
                }
            }
            res += height * (x_end - x_start) % MOD;
            prev_y = y;
        }
        return res % MOD;
    }
};


// Solution 2:

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int OPEN = 1, CLOSE = -1;
        int n = rectangles.size();
        vector<vector<int>> events(2*n);
        set<int> xvals;
        int t = 0;

        for(auto rec: rectangles) {
            if((rec[0] < ))
        }
    }
};