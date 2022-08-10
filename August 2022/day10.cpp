/*
	Convert Sorted Array to Binary Search Tree
	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
*/

// Solution: Recursion

class Solution {
public:
    TreeNode* buildTree(vector<int>& nums, int i, int j) {
        if(i > j) {
            return nullptr;
        }
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, i, mid-1);
        root->right = buildTree(nums, mid+1, j);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return buildTree(nums, 0, size-1);
    }
};