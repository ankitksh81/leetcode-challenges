/* Day 29
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3831/
*/


// Solution 1:

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        queue<pair<int, int>> q;

        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int x = it.first, y = it.second;

            if(x + 1 < m && dist[x+1][y] > dist[x][y] + 1){
                dist[x+1][y] = dist[x][y] + 1;
                q.push({x+1, y});
            }

            if(y + 1 < n && dist[x][y+1] > dist[x][y] + 1){
                dist[x][y+1] = dist[x][y] + 1;
                q.push({x, y+1});
            }

            if(x - 1 >= 0 && dist[x-1][y] > dist[x][y] + 1){
                dist[x-1][y] = dist[x][y] + 1;
                q.push({x-1, y});
            }

            if(y - 1 >= 0 && dist[x][y-1] > dist[x][y] + 1){
                dist[x][y-1] = dist[x][y] + 1;
                q.push({x, y-1});
            }

        }

        return dist;
    }
};


// Solution 2:


class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() - 1, n = mat[0].size() - 1;
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 11111));
        res[0][0] = (mat[0][0] == 0) ? 0 : res[0][0];
        res[m][n] = (mat[m][n] == 0) ? 0 : res[m][n];
        
        for (int i = 1; i < mat[0].size(); i++) {
            if (mat[0][i] == 0)
                res[0][i] = 0;
            else
                res[0][i] = min(res[0][i - 1] + 1, res[0][i]);
        }
        
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][0] == 0)
                res[i][0] = 0;
            else
                res[i][0] = min(res[i - 1][0] + 1, res[i][0]);
        }
        
        for (int i = 1; i < mat.size(); i++) {
            for (int j = 1; j < mat[0].size(); j++) {
                if (mat[i][j] == 0)
                    res[i][j] = 0;
                else
                    res[i][j] = min(res[i][j], min(res[i - 1][j], res[i][j - 1]) + 1);
            }
        }
        
        for (int i = mat[0].size() - 2; i >= 0; i--) {
            if (mat[m][i] == 0)
                res[m][i] = 0;
            else
                res[m][i] = min(res[m][i + 1] + 1, res[m][i]);
        }
        
        for (int i = mat.size() - 2; i >= 0; i--) {
            if (mat[i][n] == 0)
                res[i][n] = 0;
            else
                res[i][n] = min(res[i + 1][n] + 1, res[i][n]);
        }
        
        for (int i = mat.size() - 2; i >= 0; i--) {
            for (int j = mat[0].size() - 2; j >= 0; j--) {
                if (mat[i][j] == 0)
                    res[i][j] = 0;
                else
                    res[i][j] = min(res[i][j], min(res[i + 1][j], res[i][j + 1]) + 1);
            }
        }
        return res;
    }
};
