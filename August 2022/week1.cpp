/*
	Find Leaves of Binary Tree
	https://leetcode.com/problems/find-leaves-of-binary-tree/
*/

// Solution: Recursion

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findLeavesHelper(TreeNode* root, vector<vector<int>>& leaves) {
        if (!root) return -1;
        
        int left = findLeavesHelper(root->left, leaves);
        int right = findLeavesHelper(root->right, leaves);
        
        int height = 1 + max(left, right);
        if (leaves.size() == height) {
            leaves.push_back({});
        }
        
        leaves[height].push_back(root->val);
        return height;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        findLeavesHelper(root, leaves);
        return leaves;
    }
};