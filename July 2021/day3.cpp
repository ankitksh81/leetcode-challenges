/* Day 3
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3801/
*/

// Solution 1:

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size(), ans = INT_MIN;
        for(int l = 0; l < n; ++l) {
            vector<int> sums(m, 0);
            for(int r = l; r < n; ++r) {
                for(int c = 0; c < m; ++c) {
                    sums[c] += matrix[r][c];
                }
                set<int> accu; accu.insert(0);
                int curSum = 0;
                for(int &sum: sums) {
                    curSum += sum;
                    auto it = accu.lower_bound(curSum-k);
                    if(it != accu.end()) ans = max(ans, curSum - *it);
                    accu.insert(curSum);
                }
            }
        }
        return ans;
    }
};

// Solution 2:

class Solution {
public:
    int result = INT_MIN;
    void updateResult(vector<int>& nums, int k) {
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum resul.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // Stores the 1D representation of the matrix.
        vector<int> rowSum(matrix[0].size());
        for (int i = 0; i < matrix.size(); i++) {
            // Initialize the 1D representation with 0s.
            fill(rowSum.begin(), rowSum.end(), 0);

            // We convert the matrix between rows i..row inclusive to 1D array
            for (int row = i; row < matrix.size(); row++) {
                // Add the current row to the previous row.
                // This converts the matrix between i..row to 1D array
                for (int col = 0; col < matrix[0].size(); col++)
                    rowSum[col] += matrix[row][col];

                // Run the 1D algorithm for `rowSum`
                updateResult(rowSum, k);

                // If result is k, this is the best possible answer, so return.
                if (result == k)
                    return result;
            }
        }
        return result;
    }
};
