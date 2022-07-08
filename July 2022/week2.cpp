/*
	Inorder Successor in BST II
	https://leetcode.com/problems/inorder-successor-in-bst-ii/
*/

// Solution: Iteration with Successor & Predecessor

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* successor = nullptr, *cur = node;
        
        if(cur->right) {
            cur = cur->right;
            while (cur) {
                successor = cur;
                cur = cur->left;
            }
        }
        else {
            while(cur) {
                if(cur->val > node->val) {
                    successor = cur;
                    break;
                }
                else {
                    cur = cur->parent;
                }
            }
        }
        
        return successor;
    }
};