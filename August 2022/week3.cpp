/*
	Dot Product of Two Sparse Vectors
	https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
*/

// Solution 1: Vector (No space optimization)

class SparseVector {
public:
    vector<int> v;
    SparseVector(vector<int> &nums) {
        v = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (int i = 0; i < v.size(); i++) {
            if (vec.v[i] && v[i]) {
                res += vec.v[i] * v[i];
            }
        }
        
        return res;
    }
};


// Solution 2: Hashmap (Space optimization)

class SparseVector {
public:
    unordered_map<int, int> mp;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                mp[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (auto &[k, v] : vec.mp) {
            if (this->mp.find(k) != this->mp.end()) {
                res += (v * this->mp[k]);
            }
        }
        
        return res;
    }
};