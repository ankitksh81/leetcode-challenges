/* Day 23
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3824/
*/


// Solution:

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr){
            return root;
        }
        TreeNode* left = pruneTree(root->left);
        root->left = left;
        TreeNode* right = pruneTree(root->right);
        root->right = right;
        if(root->val == 0 && !root->right && !root->left){
            return nullptr;
        }
        return root;
    }
};
