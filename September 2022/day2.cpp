/*
	Average of Levels in Binary Tree
	https://leetcode.com/problems/average-of-levels-in-binary-tree/
*/

// Solution: BFS

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int qsize = q.size();
            long long sum = 0;
            
            for (int i = 0; i < qsize; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            double avg = sum * 1.0 / qsize;
            res.push_back(avg);
        }
        
        return res;
    }
};