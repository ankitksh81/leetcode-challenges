/* Day 7
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3805/
*/

// Solution 1:

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};


// Solution 2:

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        int n = matrix.size();

        int left = matrix[0][0], right = matrix[n-1][n-1], mid;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            int count = 0;

            for(int i=0; i<n; i++)
            {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid)- matrix[i].begin();
                // count is the count of ele less than mid in the matrix
            }

            if(count < k)
                left = mid+1;
            else
                right = mid-1;
        }

      return left;
    }
};
