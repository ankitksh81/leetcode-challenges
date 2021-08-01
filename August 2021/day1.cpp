// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3835/


// Solution 1:


class Solution {

// As 0,1 already occupied in matrix so we need to start with index = 2;
int idx=2;

// HashMap to have mapping between the connected component index and its area
unordered_map<int,int> mp;

// 4 directions to find out connected 1s
vector<pair<int,int>> direction{{1,0},{-1,0},{0,1},{0,-1}};

// Globally declaring the area variable which will store the max area
int area = 0;

// Simple DFS method for assigning connected components an index.
void dfs(int i,int j,vector<vector<int>> &grid)
{
    if(i<0 or i>=size(grid) or j<0 or j>=size(grid) or grid[i][j]!=1)
        return;
    mp[idx]++;
    grid[i][j]=idx;
    for(auto dir:direction)
    {
        dfs(i+dir.first,j+dir.second,grid);
    }
}

// Method the mark all the connected components.
void markAllTheConnectedComponents(vector<vector<int>>& grid)
{
    int n=size(grid);
    mp.clear();
    idx=2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j])
            {
                dfs(i,j,grid);
            // Here we are handling the situation when there is no 0 in the matrix.
                area=max(area,mp[idx]);
                idx++;
            }
        }
    }
}

// Method to find out the max area in case of any 0 to be flipped.
void findMaxArea(vector<vector<int>>& grid)
{
    int n=size(grid);
    queue<pair<int,int>> q;

    // Push all the {i,j} where grid[i][j]==0 in queue.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==0)
            {
                q.push({i,j});
            }
        }
    }

    auto isValid = [&](int i,int j){
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]!=0);
    };

    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        int i = front.first;
        int j = front.second;

        unordered_set<int> vis;
        int curr = 0;
        for(auto dir:direction)
        {
            int newi = i+dir.first;
            int newj = j+dir.second;

            if(isValid(newi,newj) and !vis.count(grid[newi][newj]))
            {
                vis.insert(grid[newi][newj]);
                curr += mp[grid[newi][newj]];
            }
        }
        // its curr+1, why? because we need to consider the flipped 0 also.
        area = max(curr+1,area);
    }
}


public:
    int largestIsland(vector<vector<int>>& grid)
    {
        // Step 1: Mark all the connected componentes with index.
        markAllTheConnectedComponents(grid);
        // Step 2: Do BFS to find which 0 flip will result in the larger area.
        findMaxArea(grid);
        return area;
    }
};


// Solution 2:

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int bias = 2;
        vector<int> counts;
        size_t s = grid.size();
        this->s = s;
        for (size_t i = 0; i < s; ++i) {
            for (size_t j = 0; j < s; ++j) {
                if (grid[i][j] == 1) {
                    int count = dfs(grid, i, j, counts.size() + bias);
                    counts.emplace_back(count);
                }
            }
        }

        if (counts.size() == 0) {
            return 1;
        }

        int largest = counts.front();
        for (size_t i = 0; i < s; ++i) {
            for (size_t j = 0; j < s; ++j) {
                if (grid[i][j] == 0) {
                    int top = -1;
                    int bottom = -1;
                    int left = -1;
                    int right = -1;

                    int candidate = 1;
                    if (j > 0) {
                        top = grid[i][j - 1] - bias;
                        if (top >= 0) {
                            candidate += counts[top];
                        }
                    }

                    if (i > 0) {
                        left = grid[i - 1][j] - bias;
                        if (left >= 0 && left != top) {
                            candidate += counts[left];
                        }
                    }

                    if (i + 1 < s) {
                        right = grid[i + 1][j] - bias;
                        if (right >= 0 && right != top && right != left) {
                            candidate += counts[right];
                        }
                    }

                    if (j + 1 < s) {
                        bottom = grid[i][j + 1] - bias;
                        if (bottom >= 0 && bottom != top && bottom != left && bottom != right) {
                            candidate += counts[bottom];
                        }
                    }

                    if (candidate > largest) {
                        largest = candidate;
                    }
                }
            }
        }

        return largest;
    }
    size_t s;
    int dfs(vector<vector<int>>& grid, int i, int j, int v) {
        grid[i][j] = v;
        int ret = 1;
        if (i > 0 && grid[i - 1][j] == 1) {
            ret += dfs(grid, i - 1, j, v);
        }
        if (i + 1 < s && grid[i + 1][j] == 1) {
            ret += dfs(grid, i + 1, j, v);
        }
        if (j > 0 && grid[i][j - 1] == 1) {
            ret += dfs(grid, i, j - 1, v);
        }
        if (j + 1 < s && grid[i][j + 1] == 1) {
            ret += dfs(grid, i, j + 1, v);
        }

        return ret;
    }
};
