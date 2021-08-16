// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3892/


// Solution:

class NumArray {
	vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v = nums;
        for(int i = 1; i < nums.size(); i++) {
        	v[i] = v[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0){
        	return v[right];
        }
        return (v[right] - v[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */