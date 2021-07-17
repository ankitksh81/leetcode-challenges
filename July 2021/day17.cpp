/* Day 17
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3817/
*/

// Solution 1:

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = 0;
        for(int i: arr) {
            if(i == 1)
                ones++;
        }

        if(ones == 0) {
            return {0, n-1};
        }
        if(ones % 3) {
            return {-1, -1};
        }

        int k = ones / 3;
        int i;

        for(i = 0; i < n; i++) {
            if(arr[i] == 1)
                break;
        }

        int start_idx = i;

        int count1 = 0;
        for(i = 0; i < n; i++){
            if(arr[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }

        int mid = i;

        count1 = 0;
        for(i = 0; i < n; i++) {
            if(arr[i] == 1) {
                count1++;
            }
            if(count1 == 2*k + 1)
                break;
        }

        int end_idx = i;

        while(end_idx < n and arr[start_idx] == arr[mid] and arr[mid] == arr[end_idx]) {
            start_idx++;
            mid++;
            end_idx++;
        }

        if(end_idx == n) {
            return {start_idx - 1, mid};
        }
        return {-1, -1};
    }
};


// Solution 2:

class Solution {
public:
    vector<int> threeEqualParts(vector<int> &A) {
        int n = A.size();
        vector<int> vi;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 1) {
                vi.push_back(i);
            }
        }
        int m = vi.size();
        if (m == 0)
            return vector{0, 2};
        if (m % 3 != 0)
            return vector{-1, -1};
        int len = n - vi[m / 3 * 2];
        int a = vi[0], b = vi[m / 3], c = vi[m / 3 * 2];
        for (int i = 0; i < len; ++i) {
            if (A[a + i] != A[b + i] || A[a + i] != A[c + i]) {
                return vector{-1, -1};
            }
        }
        return vector{a + len - 1, b + len};
    }
};
