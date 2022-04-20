/*
	Binary Search Tree Iterator
	https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
    stack<TreeNode*> nodes;
    
    void pushAll(TreeNode* root) {
        for(TreeNode* cur = root; cur != nullptr; cur = cur->left) {
            nodes.push(cur);
        }
    }
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* curNode = nodes.top();
        nodes.pop();
        pushAll(curNode->right);
        
        return curNode->val;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */