/*
    Construct binary tree from inorder and postorder traversal
    https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd,
            vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorder_map) {
    if(postStart > postEnd || inStart > inEnd) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inorder_map[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1, inorder,
                    inStart, inRoot-1, inorder_map);

    root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1, inorder,
                    inRoot+1, inEnd, inorder_map);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorder_map;
    int n = inorder.size(), m = postorder.size();

    for(int i = 0; i < n; i++) {
        inorder_map[inorder[i]] = i;
    }

    TreeNode* root = buildTreeHelper(postorder, 0, m-1, inorder, 0, n-1, inorder_map);

    return root;
}
};