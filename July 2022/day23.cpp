/*
	Count of Smaller Numbers After Self
	https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/

// Solution 1: Merge Sort

class Solution {
    vector<int> result;
public:
    void merge(vector<int>& indices, int l, int r, vector<int>& nums) {
        int mid = (l + r) / 2;
        int i = l, j = mid;
        vector<int> temp;
        while (i < mid && j < r) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                result[indices[i]] += j - mid;
                temp.push_back(indices[i]);
                i++;
            }
            else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        
        while (i < mid) {
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        while (j < r) {
            temp.push_back(indices[j]);
            j++;
        }
        
        move(temp.begin(), temp.end(), indices.begin() + l);
    }
    
    void mergeSort(vector<int>& indices, int l, int r, vector<int>& nums) {
        if (r - l <= 1) return;
        
        int mid = l + (r - l) / 2;
        mergeSort(indices, l, mid, nums);
        mergeSort(indices, mid, r, nums);
        merge(indices, l, r, nums);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int N = nums.size();
        result.resize(N);
        vector<int> indices(N);
        for (int i = 0; i < N; i++) {
            indices[i] = i;
        }
        
        mergeSort(indices, 0, N, nums);
        return result;
    }
};


// Solution 2: Fenwick Tree

class BIT {
    vector<int> bit;
public:
    BIT(int n): bit(n+1, 0) {}
    
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }
    
    void update(int i, int value) {
        for (++i; i < bit.size(); i += (i & -i)) {
            bit[i] += value;
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int BASE = 1e4;
        int N = nums.size();
        BIT bit(2 * 1e4 + 1);
        
        vector<int> res(N, 0);
        for (int i = N-1; i >= 0; i--) {
            res[i] = bit.query(BASE + nums[i] - 1);
            bit.update(BASE + nums[i], 1);
        }
        
        return res;
    }
};