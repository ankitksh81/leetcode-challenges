// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3908/


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
    unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr) {
            return false;
        }
        if(s.count(k - root->val)) {
            return true;
        }
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};


// Solution 2:

class Solution {
	vector<int> vec;
public:
	void inorder(TreeNode* root) {
		if(root == nullptr) {
			return;
		}

		inorder(root->left);
		vec.push_back(root->val);
		inorder(root->right);
	}

	bool findTarget(TreeNode* root, int k) {
		inorder(root);
		int l = 0, r = vec.size()-1;

		while(l < r) {
			if(vec[l] + vec[r] == k)
				return true;
			else {
				if(vec[l] + vec[r] < k)
					l++;
				else
					r--;
			}
		}
		return false;
	}
};