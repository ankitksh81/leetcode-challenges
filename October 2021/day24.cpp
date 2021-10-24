/*
    Count complete tree nodes
    https://leetcode.com/problems/count-complete-tree-nodes/
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
    int findLeftHeight(TreeNode* root) {
        TreeNode* cur = root;
        int height = 0;
        while(cur) {
            height++;
            cur = cur->left;
        }
        return height;
    }
    
    int findRightHeight(TreeNode* root) {
        TreeNode* cur = root;
        int height = 0;
        while(cur) {
            height++;
            cur = cur->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        int lheight = findLeftHeight(root);
        int rheight = findRightHeight(root);
        
        if(lheight == rheight) {
            return (1 << lheight) - 1;
        }
        
        return 1 + (countNodes(root->left) + countNodes(root->right));
    }
};