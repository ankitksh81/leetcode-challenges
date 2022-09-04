/*
	Vertical Order Traversal of a Binary Tree
	https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

// Solution: BFS

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int x = it.second.first, y = it.second.second;
            
            mp[x][y].insert(node->val);
            if (node->left) {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto &it : mp) {
            vector<int> cur;
            for (auto &[y, s] : it.second) {
                for (int x : s) {
                    cur.push_back(x);
                }
            }
            result.push_back(cur);
        }
        
        return result;
    }
};