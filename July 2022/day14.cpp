/*
	Construct Binary Tree from Preorder and Inorder Traversal
	https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

// Solution: Recursion

class Solution {
    unordered_map<int, int> inorder_map;
public:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = build(preorder, preStart + 1, preStart + numsLeft,
                          inorder, inStart, inRoot - 1);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd,
                           inorder, inRoot + 1, inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};