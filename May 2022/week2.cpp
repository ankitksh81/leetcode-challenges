/*
	Robot Room Cleaner
	https://leetcode.com/problems/robot-room-cleaner/
*/

// Solution 1: Backtracking

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    vector<vector<int>> dir {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    set<pair<int, int>> vis;
public:
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void backtrack(int r, int c, int d, Robot& robot) {
        vis.insert({r, c});
        robot.clean();
        for(int i = 0; i < 4; i++) {
            int newD = (d + i) % 4;
            int newR = r + dir[newD][0];
            int newC = c + dir[newD][1];
            
            if(!vis.count(pair<int, int>(newR, newC)) && robot.move()) {
                backtrack(newR, newC, newD, robot);
                goBack(robot);
            }
            
            robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        backtrack(0, 0, 0, robot);
    }
};

// Solution 2:

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        size_t hash1 = hash<T1>{}(p.first);
        size_t hash2 = hash<T2>{}(p.second);
        
        return (hash1 != hash2) ? hash1 ^ hash2 : hash1;
    }
};

class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    unordered_set<pair<int, int>, hash_pair> visited;
    
    void goBack(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void clean(int r, int c, int d, Robot& robot) {
        visited.insert({r, c});
        robot.clean();
        
        for (int i = 0; i < 4; i++) {
            int dir = (d + i) % 4;
            int x = r + dirs[dir][0];
            int y = c + dirs[dir][1];
            
            if (!visited.count(pair<int, int>(x, y)) && robot.move()) {
                clean(x, y, dir, robot);
                goBack(robot);
            }
            
            robot.turnRight();
        }
    }
    
public:
    void cleanRoom(Robot& robot) {
        clean(0, 0, 0, robot);
    }
};