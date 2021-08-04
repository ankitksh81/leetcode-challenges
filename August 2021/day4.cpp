// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3838/


// Solution:

class Solution {
public:
    
    void findPath(TreeNode* root, int targetSum, int cur_sum, vector<int>& cur_path, vector<vector<int>>& ans){
        if(root == nullptr){
            return;
        }
        cur_sum += root->val;
        cur_path.push_back(root->val);
        
        if(cur_sum == targetSum && root->left == nullptr && root->right == nullptr){
            ans.push_back(cur_path);
        }
        
        findPath(root->left, targetSum, cur_sum, cur_path, ans);
        findPath(root->right, targetSum, cur_sum, cur_path, ans);
        
        cur_path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur_path;
        int cur_sum = 0;
        findPath(root, targetSum, cur_sum, cur_path, ans);
        return ans;
    }
};