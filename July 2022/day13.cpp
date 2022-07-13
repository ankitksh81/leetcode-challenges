/*
	Binary Tree Level Order Traversal
	https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

// Solution: BFS

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            vector<int> curLevel;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                curLevel.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            result.push_back(curLevel);
        }
        
        return result;
    }
};