/*
    Binary tree tilt
    https://leetcode.com/problems/binary-tree-tilt/
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
    int findTiltUtil(TreeNode* root, int &tilt) {
        if(root == nullptr) {
            return 0;
        }
        
        int leftTilt = findTiltUtil(root->left, tilt);
        int rightTilt = findTiltUtil(root->right, tilt);
        
        tilt += abs(rightTilt - leftTilt);
        return root->val + leftTilt + rightTilt;
    }
    
    int findTilt(TreeNode* root) {
        int tilt = 0;
        findTiltUtil(root, tilt);
        return tilt;
    }
};