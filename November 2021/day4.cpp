/*
    Sum of left leaves
    https://leetcode.com/problems/sum-of-left-leaves/
*/

// Solution:

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
    void findSum(TreeNode* root, int &sum) {
        if(root == nullptr) {
            return;
        }
        if(root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }
        findSum(root->left, sum);
        findSum(root->right, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        findSum(root, sum);
        return sum;
    }
};