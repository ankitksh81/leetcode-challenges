// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3870/


// Solution:

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int l = 0, r = n-1, alex_sum = 0, lee_sum = 0;
        int chance = 1;
        while(l < r){
            if(piles[l] > piles[r]){
                if(chance == 1){
                    alex_sum += piles[l++];
                }
                else{
                    lee_sum += piles[l++];
                }
            }
            else {
                if(chance == 1){
                    alex_sum += piles[r--];
                }
                else{
                    lee_sum += piles[r--];
                }
            }
        }
        return (alex_sum > lee_sum);
    }
};
