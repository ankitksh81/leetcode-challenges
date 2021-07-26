/* Day 26
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3827/
*/

// Solution 1:

class Solution {
public:
    using it = vector<int>::const_iterator;
    TreeNode* convert(it begin, it end){
            if(begin >= end)
                return nullptr;

            const auto mid = begin + (end - begin) / 2;
            return new TreeNode(*mid, convert(begin, mid), convert(mid+1, end));
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums.cbegin(), nums.cend());
    }
};


// Solution 2:

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int low, int high) {
        if(high < low)
        {
            return NULL;
        }
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, low , mid-1);
        root->right = helper(nums, mid+1, high);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
