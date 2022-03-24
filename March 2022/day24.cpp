/*
	Boats to Save People
	https://leetcode.com/problems/boats-to-save-people/
*/

// Solution: Greedy + Two Pointers

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boats = 0;
        int l = 0, r = people.size()-1;
        
        while(l <= r) {
            boats++;
            if(people[r] + people[l] > limit) {
                r--;
            }
            else if(people[r] + people[l] <= limit) {
                r--;
                l++;
            }
        }
        
        return boats;
    }
};