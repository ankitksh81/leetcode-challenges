/*
	Binary Tree vertical Order Traversal
	https://leetcode.com/problems/binary-tree-vertical-order-traversal/
*/

// Solution: Level Order Traversal

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode* node = q.front().first;
                int x = q.front().second;
                q.pop();
                
                mp[x].push_back(node->val);
                if (node->left) {
                    q.push({node->left, x-1});
                }
                if (node->right) {
                    q.push({node->right, x+1});
                }
            }
        }
        
        vector<vector<int>> result;
        for (auto &[k, v] : mp) {
            result.push_back(v);
        }
        
        return result;
    }
};