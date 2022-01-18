/*
	Can Place Flowers
	https://leetcode.com/problems/can-place-flowers/
*/

// Solution 1: Single Pass

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, cnt = 0;
        while(i < flowerbed.size()) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && 
               (i == flowerbed.size()-1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                cnt++;
            }
            i++;
        }
        return cnt >= n;
    }
};

// Solution 2: Optimized Single Pass

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, cnt = 0;
        while(i < flowerbed.size()) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && 
               (i == flowerbed.size()-1 || flowerbed[i + 1] == 0)) {
                flowerbed[i++] = 1;
                cnt++;
            }
            if(cnt >= n) {
                return true;
            }
            i++;
        }
        return false;
    }
};