/*
    Sum of Root to Leaf Binary Numbers
    https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    void findSum(TreeNode* root, int n, int &sum) {
        if(root == nullptr) 
            return;
        
        if(!root->left && !root->right) {
            int i = root->val;
            n = (n << 1) | i;
            sum += n;
        }
        
        if(root->left) {
            int i = root->val;
            findSum(root->left, ((n << 1) | i), sum);
        }
        if(root->right) {
            int i = root->val;
            findSum(root->right, ((n << 1) | i), sum);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        findSum(root, 0, sum);
        return sum;
    }
};
