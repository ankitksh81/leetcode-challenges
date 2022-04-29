/*
	Encode N-ary Tree to Binary Tree
	https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
*/

// Solution: BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root) {
            return nullptr;
        }
        
        queue<pair<TreeNode*, Node*>> q;
        
        TreeNode* bRoot = new TreeNode(root->val);
        q.push({bRoot, root});
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            TreeNode* bNode = node.first;
            Node* nNode = node.second;
            
            // Encoding the children nodes into a list of TreeNode
            TreeNode* prevBNode = nullptr, *headBNode = nullptr;
            
            for (Node* nChild : nNode->children) {
                TreeNode* newBNode = new TreeNode(nChild->val);
                if (!prevBNode) {
                    headBNode = newBNode;
                }
                else {
                    prevBNode->right = newBNode;
                }
                prevBNode = newBNode;
                
                q.push({newBNode, nChild});
            }
            
            bNode->left = headBNode;
        }
        
        return bRoot;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        
        Node* nRoot = new Node(root->val);
        
        queue<pair<Node*, TreeNode*>> q;
        q.push({nRoot, root});
        
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            
            Node* nNode = node.first;
            TreeNode* bNode = node.second;
            
            // Decoding the children list
            TreeNode *firstChild = bNode->left;
            TreeNode *sibling = firstChild;
            
            while (sibling != nullptr) {
                Node* nChild = new Node(sibling->val);
                nNode->children.push_back(nChild);
                
                q.push({nChild, sibling});
                sibling = sibling->right;
            }
        }
        
        return nRoot;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));