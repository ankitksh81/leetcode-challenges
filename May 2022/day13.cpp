/*
	Populating Next Right Pointers in Each Node II
	https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
*/

// Solution: BFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                Node* curNode = q.front();
                q.pop();
                
                if (i == qsize - 1) {
                    curNode->next = nullptr;
                }
                else {
                    curNode->next = q.front();
                }
                
                if (curNode->left) {
                    q.push(curNode->left);
                }
                if (curNode->right) {
                    q.push(curNode->right);
                }
            }
        }
        
        return root;
    }
};