/*
	Binary Tree Longest Consecutive Sequence
	https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
*/

// Solution: DFS

class Solution {
    int findLongestConsecutive(TreeNode* root, TreeNode* par, int len) {
        if (!root) return len;
        len = (par && root->val == par->val + 1) ? len + 1 : 1;
        
        return max(len, max(findLongestConsecutive(root->left, root, len),
                            findLongestConsecutive(root->right, root, len)));
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        return findLongestConsecutive(root, nullptr, 0);
    }
};