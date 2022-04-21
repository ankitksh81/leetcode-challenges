/*
	Design HashSet
	https://leetcode.com/problems/design-hashset/
*/

// Solution: Binary Search Tree

struct BST {
    TreeNode* root = nullptr;
    
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || val == root->val) {
            return root;
        }
        
        return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
    
    TreeNode* insertBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        
        if(val > root->val) {
            root->right = insertBST(root->right, val);
        }
        else if(val == root->val) {
            return root;
        }
        else {
            root->left = insertBST(root->left, val);
        }
        
        return root;
    }
    
    int successor(TreeNode* root) {
        root = root->right;
        while(root->left) {
            root = root->left;
        }
        return root->val;
    }
    
    int predecessor(TreeNode* root) {
        root = root->left;
        while(root->right) {
            root = root->right;
        }
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) {
            return nullptr;
        }
        
        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if(!root->left && !root->right) {
                root = nullptr;
            }
            else if(root->right) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
            else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }
        
        return root;
    }
};

class Bucket {
    BST* tree;
public:
    Bucket() {
        tree = new BST();
    }
    
    void insert(int key) {
        tree->root = tree->insertBST(tree->root, key);
    }
    
    void deleteKey(int key) {
        tree->root = tree->deleteNode(tree->root, key);
    }
    
    bool exists(int key) {
        TreeNode* node = tree->searchBST(tree->root, key);
        return node != nullptr;
    }
};

class MyHashSet {
    vector<Bucket> arr;
    int keyRange;
    
    int hash(int key) {
        return (key % keyRange);
    }
    
public:
    MyHashSet() {
        keyRange = 769;
        arr.resize(keyRange);
    }
    
    void add(int key) {
        int bucketIdx = hash(key);
        arr[bucketIdx].insert(key);
    }
    
    void remove(int key) {
        int bucketIdx = hash(key);
        arr[bucketIdx].deleteKey(key);
    }
    
    bool contains(int key) {
        int bucketIdx = hash(key);
        return arr[bucketIdx].exists(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */