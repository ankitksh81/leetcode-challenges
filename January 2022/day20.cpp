/*
	Koko Eating Bananas
	https://leetcode.com/problems/koko-eating-bananas/
*/

// Solution 1: Brute Force

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {    
        int speed = 1;

        while (true) {
            int hourSpent = 0;

            for (int pile : piles) {
                hourSpent += pile / speed + (pile % speed != 0);
                if (hourSpent > h) {
                    break;
                }
            }

            if (hourSpent <= h) {
                return speed;
            } else {
                speed += 1;
            }            
        }
    }
};

// Solution 2: Binary Search

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {      
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int middle = (left + right) / 2;
            int hourSpent = 0;

            for (int pile : piles) {
                hourSpent += pile / middle + (pile % middle != 0);
            }

            if (hourSpent <= h) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }

        return right;
    }
};
