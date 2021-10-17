/*
    Path sum III
    https://leetcode.com/problems/path-sum-iii/
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
    void findPaths(TreeNode* root, int target, unordered_map<int, int>& mp, int &cnt, int sum) {
        if(root == nullptr) {
            return;
        }
        sum += root->val;
        if(sum == target) {
            cnt++;
        }
        if(mp.find(sum - target) != mp.end()) {
            cnt += mp[sum - target];
        }
        mp[sum]++;
        findPaths(root->left, target, mp, cnt, sum);
        findPaths(root->right, target, mp, cnt, sum);
        mp[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return 0;
        }
        unordered_map<int, int> mp;
        int cnt = 0;
        findPaths(root, targetSum, mp, cnt, 0);
        return cnt;
    }
};