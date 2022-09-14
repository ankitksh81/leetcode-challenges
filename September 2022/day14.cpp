/*
        Pseudo-Palindromic Paths in a Binary Tree
        https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/

// Solution: Recursion + Bit Masking

class Solution {
    unordered_set<int> powerOfTwo = {2, 4, 8, 16, 32, 64, 128, 256, 512};
public:
    void findPaths(TreeNode* root, int mask, int &res) {
        if (!root) return;
        
        int bit = (1 << root->val);
        findPaths(root->left, mask ^ bit, res);
        findPaths(root->right, mask ^ bit, res);
        
        if (!root->left && !root->right) {
            if ((mask ^ bit) == 0 || powerOfTwo.find((mask ^ bit)) != powerOfTwo.end()) {
                res++;
            }
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0, mask = 0;
        findPaths(root, mask, res);
        return res;
    }
};
