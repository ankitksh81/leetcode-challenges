/*
        Path Sum II
        https://leetcode.com/problems/path-sum-ii/
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
    void findPathSum(TreeNode* root, vector<int>& cur, int target, vector<vector<int>>& res) {
        if (!root) return;
        
        cur.push_back(root->val);
        
        findPathSum(root->left, cur, target - root->val, res);
        findPathSum(root->right, cur, target - root->val, res);
        
        if (!root->left && !root->right && target == root->val) {
            res.push_back(cur);
        }
        
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> cur;
        findPathSum(root, cur, targetSum, result);
        return result;
    }
};
