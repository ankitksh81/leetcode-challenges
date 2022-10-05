/*
	Add One Row to Tree
	https://leetcode.com/problems/add-one-row-to-tree/description/
*/

// Solution: Recursion

class Solution {
public:
    void addrow(TreeNode *root, int val, int depth){
        if (!root) return ;
        if (depth == 1) {
            TreeNode *leftChild = root->left;
            TreeNode *rightChild = root->right;
            
            TreeNode *newNode = new TreeNode(val);
            root->left = newNode;
            newNode->left = leftChild;
            
            newNode = new TreeNode(val);
            root->right = newNode;
            newNode->right = rightChild;
        }
        addrow(root->left,val,depth-1);
        addrow(root->right,val,depth-1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {      
        if (!root && depth == 1) {
            return new TreeNode(val);
        }
        
        if (depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            newRoot->right = nullptr;
            return newRoot;
        }
		
        depth -= 1;
        addrow(root, val, depth);
    
        return root;
    }
};
