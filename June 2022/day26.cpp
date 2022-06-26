/*
	Maximum Points You Can Obtain from Cards
	https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
*/

// Solution: Sliding Window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int N = cardPoints.size();
        int sum = accumulate(begin(cardPoints), end(cardPoints), 0);
        int cur_sum = 0, l = 0, r = 0, min_sum = sum;
        
        while (r < N) {
            cur_sum += cardPoints[r++];
            if (r - l > N-k) {
                cur_sum -= cardPoints[l++];
            }
            
            if (r - l == N-k) {
                min_sum = min(min_sum, cur_sum);
            }
        }
        
        return sum - min_sum;
    }
};