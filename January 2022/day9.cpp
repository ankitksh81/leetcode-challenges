/*
	Robot Bounded In Circle
	https://leetcode.com/problems/robot-bounded-in-circle/
*/

// Solution:

class Solution {
public:
    void move(int &x, int &y, int &dir) {
        if(dir == 0)        y++;
        else if(dir == 1)   x--;
        else if(dir == 2)   y--;
        else                x++;
    }
    
    void changeDir(int &dir, char &c) {
        if(c == 'L') {
            if(dir == 0)        dir = 1;
            else if(dir == 1)   dir = 2;
            else if(dir == 2)   dir = 3;
            else                dir = 0;
        } else {
            if(dir == 0)        dir = 3;
            else if(dir == 1)   dir = 0;
            else if(dir == 2)   dir = 1;
            else                dir = 2;
        }
    }
    
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        for(char instruction: instructions) {
            if(instruction == 'G') {
                move(x, y, dir);
            }
            else {
                changeDir(dir, instruction);
            }
        }
        
        if(x == 0 && y == 0) {
            return true;
        }
        return (dir != 0);
    }
};