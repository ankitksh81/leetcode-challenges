/*
	The Number of Weak Characters in the Game
	https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
*/

// Solution 1: Sorting

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]);
        });
        
        int res = 0;
        int maxDefense = 0;
        
        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < maxDefense) {
                res++;
            }
            maxDefense = max(maxDefense, properties[i][1]);
        }
        
        return res;
    }
};


// Solution 2: Greedy

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxAttack = 0;
        for (vector<int>& property : properties) {
            int attack = property[0];
            maxAttack = max(maxAttack, attack);
        }
        
        vector<int> maxDefense(maxAttack + 2, 0);
        for (vector<int>& property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            maxDefense[attack] = max(maxDefense[attack], defense);
        }
        
        for (int i = maxAttack - 1; i >= 0; i--) {
            maxDefense[i] = max(maxDefense[i], maxDefense[i+1]);
        }
        
        int res = 0;
        for (vector<int> &property : properties) {
            int attack = property[0];
            int defense = property[1];
            
            if (defense < maxDefense[attack + 1]) {
                res++;
            }
        }
        
        return res;
    }
};