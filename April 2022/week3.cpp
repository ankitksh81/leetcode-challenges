/*
	Binary Search Tree Iterator II
	https://leetcode.com/problems/binary-search-tree-iterator-ii/
*/

// Solution: Using Stack

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
    stack<TreeNode*> nextNodes;
    vector<int> nodeValues;
    int idx;
    
    void pushAll(TreeNode* root) {
        for (; root != nullptr; root = root->left) {
            nextNodes.push(root);
        }
    }
    
public:
    
    BSTIterator(TreeNode* root) {
        idx = -1;
        pushAll(root);
    }
    
    bool hasNext() {
        return !nextNodes.empty() || (idx + 1 < nodeValues.size());
    }
    
    int next() {
        if (++idx == nodeValues.size()) {
            TreeNode* cur = nextNodes.top();    nextNodes.pop();
            pushAll(cur->right);
            nodeValues.push_back(cur->val);
        }
        
        return nodeValues[idx];
    }
    
    bool hasPrev() {
        return idx > 0;
    }
    
    int prev() {
        return nodeValues[--idx];
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */