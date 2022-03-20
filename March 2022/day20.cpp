/*
	Minimum Domino Rotations For Equal Row
	https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/

// Solution: Greedy

class Solution {
public:
    int getMinRotations(vector<int>& tops, vector<int>& bottoms, int val) {
        int rotations1 = 0, rotations2 = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != val && bottoms[i] != val) {
                return -1;
            }
            
            if (tops[i] != val) {
                rotations1++;
            } else if (bottoms[i] != val) {
                rotations2++;
            }
        }
        
        return min(rotations1, rotations2);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int rotations = getMinRotations(tops, bottoms, tops[0]);
        
        if (rotations != -1 || tops[0] == bottoms[0]) {
            return rotations;
        }
        
        return getMinRotations(tops, bottoms, bottoms[0]);
    }
};