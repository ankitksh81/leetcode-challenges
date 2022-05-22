/*
	Find the Celebrity
	https://leetcode.com/problems/find-the-celebrity/
*/

// Solution: Logical Deduction

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool isCelebrity(int i, int n) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            if(knows(i, j) || !knows(j, i)) {
                return false;
            }
        }
        return true;
    }
    
    int findCelebrity(int n) {
        int celebCandidate = 0;
        for(int i = 1; i < n; i++) {
            if(knows(celebCandidate, i)) {
                celebCandidate = i;
            }
        }
        
        if(isCelebrity(celebCandidate, n)) {
            return celebCandidate;
        }
        return -1;
    }
};