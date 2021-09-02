// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3961/


// Solution 1:

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
	vector<TreeNode*> helper(int start, int end) {
		vector<TreeNode*> res;
		if(start > end) {
			return {nullptr};
		}
		if(start == end) {
			return {new TreeNode(start)};
		}
		
		for(int i = start; i <= end; i++) {
			vector<TreeNode*> left = helper(start, i-1), right = helper(i+1, end);
			
			for(auto l: left) {
				for(auto r: right) {
					res.push_back(new TreeNode(i, l, r));
				}
			}
		}
		
		return res;
	}
	
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> ans = helper(1, n);
		return ans;
	}
};


// Solution 2:

class Solution {
	vector<TreeNode*> dp[10][10];
public:
	vector<TreeNode*> helper(int start, int end) {
		vector<TreeNode*> res;
		if(start > end) {
			res.push_back(nullptr);
			return res;
		}
		if(dp[start][end].size() != 0)
			return dp[start][end];
		for(int i = start; i <= end; i++) {
			vector<TreeNode*> tempLeft = helper(start, i - 1);
			vector<TreeNode*> tempRight = helper(i + 1, end);
			
			for(int j = 0; j < tempLeft.size(); j++) {
				for(int k = 0; k < tempRight.size(); k++) {
					TreeNode* node = new TreeNode(i);
					node->left = tempLeft[j];
					node->right = tempRight[k];
					res.push_back(node);
				}
			}
		}
		dp[start][end] = res;
		return dp[start][end];
	}
	
	vector<TreeNode*> generateTrees(int n) {
		return helper(1, n);
	}
};