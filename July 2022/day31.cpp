/*
	Range Sum Query - Mutable
	https://leetcode.com/problems/range-sum-query-mutable/
*/

// Solution 1: Square Root Decomposition

class NumArray {
private:
    vector<int> v, nums;
    int len;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        double l = sqrt(nums.size());
        len = (int)ceil(nums.size() / l);
        v.resize(len);
        
        for(int i = 0; i < nums.size(); i++) {
            v[i / len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int v_l =  index / len;
        v[v_l] = v[v_l] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        int startBlock = left / len;
        int endBlock = right / len;
        if(startBlock == endBlock) {
            for(int k = left; k <= right; k++) {
                sum += nums[k];
            }
        } else {
            for(int k = left; k <= (startBlock + 1) * len - 1; k++) {
                sum += nums[k];
            }
            for(int k = startBlock + 1; k <= endBlock - 1; k++) {
                sum += v[k];
            }
            for(int k = endBlock * len; k <= right; k++) {
                sum += nums[k];
            }
        }
        return sum;
    }
};


// Solution 2: Binary Indexed Tree

class NumArray {
    vector<int> bit;
    int size;
    
    int sum(int x) {
        int res = 0;
        while (x) {
            res += bit[x];
            x -= (x & -x);
        }
        
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        bit = vector<int>(size + 1);
        for (int i = 0; i < size; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        index++;
        val -= sum(index) - sum(index-1);
        while (index <= size) {
            bit[index] += val;
            index += (index & -index);
        }
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */