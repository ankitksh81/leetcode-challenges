/*
	Find a corresponding Node of a Binary Tree in a clone of That Tree
	https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
*/

// Solution: Recursion

class Solution {
    TreeNode* result;
    void solve(TreeNode* orig, TreeNode* copy, TreeNode* target) {
        if (!orig)  return;
        
        if (orig == target) {
            result = copy;
            return;
        }
        
        solve(orig->left, copy->left, target);
        solve(orig->right, copy->right, target);
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        result = nullptr;
        solve(original, cloned, target);
        return result;
    }
};