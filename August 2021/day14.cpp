// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3889/


// Solution 1:

class Solution {
public:
    int dp[100][100][100];
    int solve(vector<int>& boxes, int i, int j, int k) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        
        int res = (k+1) * (k+1) + solve(boxes, i+1, j, 0);
        
        for(int it = i+1; it <= j; it++) {
            if(boxes[it]==boxes[i]) {
                res = max(res, solve(boxes, i+1, it-1, 0) + solve (boxes, it, j, k+1));
            }
        }
        return dp[i][j][k] = res;
    }
    
    int removeBoxes(vector<int>& boxes)
    {    
        memset(dp,-1,sizeof(dp));
        return solve(boxes, 0, boxes.size()-1, 0);   
    }
};


// Solution 2:

class BoxRun {
public:
    short color, count;
};

typedef ushort score_t;

const size_t N = 100;
uint test_n = 0;
score_t cache[(N + 1) * (N + 1) * (N + 1)];
BoxRun runs[N];


class Solution {
public:
    inline score_t dfs(int i, int j, int k)
    {
        score_t* cached = &cache[k * test_n * test_n + i * test_n + j];
        if (*cached != 0) {
            return *cached;
        }
        short color = runs[i].color;
        if ((j - i) > 1 && runs[j - 1].color == color) {
            k += runs[i++].count + runs[--j].count;
        }
        else {
            k += runs[i++].count;
        }
        score_t score = k * k;
        if (i != j) {
            score += dfs(i, j, 0);
            for (int mid = i + 1; mid < j - 1; ++mid) {
                if (runs[mid].color == color) {
                    score_t score_for_remove = dfs(i, mid, 0);
                    score_t score_for_join = dfs(mid, j, k);
                    score_t attempt_score = score_for_remove + score_for_join;
                    if (attempt_score > score) {
                        score = attempt_score;
                    }
                }
            }
        }
        *cached = score;
        return score;
    }

    int removeBoxes(vector<int>& boxes)
    {
        short color = -1;
        short count = 0;
        BoxRun* runs_end = runs;
        for (int bi = 0; bi < boxes.size(); ++bi) {
            int box = boxes[bi];
            if (box == color) {
                count += 1;
            }
            else {
                if (color != -1) {
                    *runs_end++ = { color, count };
                }
                color = box;
                count = 1;
            }
        }
        *runs_end++ = { color, count };
        test_n = runs_end - runs + 1;
        memset(cache, 0, test_n * test_n * boxes.size() * sizeof(score_t));
        return dfs(0, runs_end - runs, 0);
    }
};