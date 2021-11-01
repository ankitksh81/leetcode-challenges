/*
    Surrounded Regions
    https://leetcode.com/problems/surrounded-regions/
*/

// Solution 1: DFS

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        
        // If board have less than 3 size in any direction: nothing to do, because all cells located on borders
        if (n < 3 || m < 3) {
            return;
        }
        boardPtr = &board;        
        
        // Go and check left and right borders of the board
        for (auto row = 0; row < n; ++row) {
            if (board[row][0] == 'O') {
                dfs(row, 0);
            }
            if (board[row][m - 1] == 'O') {
                dfs(row, m - 1);
            }
        }
        // Same for check up and down borders of the board
        // Since corners (0,0) and (n - 1, m - 1) where checked in previous cycle, skip them in this one
        for (auto col = 1; col < m - 1; ++col) {
            if (board[0][col] == 'O') {
                dfs(0, col);
            }
            if (board[n - 1][col] == 'O') {
                dfs(n - 1, col);
            }
        }
        
        // Follow through the whole board and flip all 'R' cells back into 'O' and all 'O' cell to 'X'
        // since they're unreacheable from the board located 'O' cell if any
        for (auto row = 0; row < n; ++row) {
            for (auto col = 0; col < m; ++col) {
                if (board[row][col] == 'O') {
                    board[row][col] = 'X';
                }
                else if (board[row][col] == 'R') {
                    board[row][col] = 'O';
                }
            }
        }
    }

private:
    // DFS to look for the next 'O' cell upper, lower, to the right and to the left of current coordinates
    // If 'O' cell is found, recursevly mark this cell as 'R' which is mean REACHED
    void dfs(int row, int col) {
        boardPtr->at(row)[col] = 'R';
        if (row > 0 && boardPtr->at(row - 1)[col] == 'O') {
            dfs(row - 1, col);
        }
        if (row < n - 1 && boardPtr->at(row + 1)[col] == 'O') {
            dfs(row + 1, col);
        }
        if (col > 0 && boardPtr->at(row)[col - 1] == 'O') {
            dfs(row, col - 1);
        }
        if (col < m - 1 && boardPtr->at(row)[col + 1] == 'O') {
            dfs(row, col + 1);
        }
    }
    
private:
    vector<vector<char>>* boardPtr;
    int n;
    int m;
};

// Solution 2: Union Find

class UnionFind {
private:
    vector<int> id;
    vector<int> sz;

public:
    UnionFind (int n) {
        id.resize(n);
        iota(id.begin(), id.end(), 0);
        sz.resize(n, 1);
    }
    
    int find(int x) {
        if (x == id[x]) 
            return x;
        return id[x] = find(id[x]);
    }
  
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
  
    bool merge(int x, int y) {
        int i = find(x), j = find(y);
        if(i == j) 
            return false;
        if(sz[j] > sz[i]) {
            swap(i, j);
            swap(sz[i], sz[j]);
        }
        id[j] = i;
        sz[i] += sz[j];
        return true;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size(), bound = m * n;
        UnionFind uf(m * n + 1);
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        unordered_set<int> visited;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 'X' || visited.count(i * n + j))
                    continue;
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    uf.merge(i * n + j, bound);
                for(int d = 0; d < 4; ++d) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 'O' && visited.count(i * n + j) == 0) {
                        uf.merge(i * n + j, ni * n + nj);
                    }
                }
                visited.insert(i * n + j);
            }
        }
        for(auto& p : visited) {
            if(!uf.connected(bound, p)) {
                int i = p / n, j = p % n;
                board[i][j] = 'X';
            }
        }
    }
};