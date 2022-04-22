/*
	Design File System
	https://leetcode.com/problems/design-file-system/
*/

// Solution 1: Trie

class Trie {
public:
    bool isPath;
    int value;
    unordered_map<char, Trie*> child;
    Trie() : isPath(false), value(-1) {}
};

class FileSystem {
    Trie *root;
    
    bool insertPath(Trie* root, string &path, int val) {
        Trie* cur = root;
        // for(char c : path) {
        //     if(cur->child.find(c) == cur->child.end()) {
        //         cur->child[c] = new Trie();
        //     }
        //     cur = cur->child[c];
        // }
        
        for(int i = 0; i < path.length(); i++) {
            char c = path[i];
            if(i < path.length() - 1 && path[i+1] == '/') {
                if(cur->child.find(c) == cur->child.end()) {
                    return false;
                }
                cur = cur->child[c];
                if(!cur->isPath) {
                    return false;
                }
            }
            else {
                if(cur->child.find(c) == cur->child.end()) {
                    cur->child[c] = new Trie();
                }
                cur = cur->child[c];
            }
        }
        
        if(cur->isPath) {
            return false;
        }
        
        cur->isPath = true;
        cur->value = val;
        return true;
    }
    
    int getPathValue(Trie* root, string &path) {
        Trie *cur = root;
        for(char c : path) {
            if(cur->child.find(c) == cur->child.end()) {
                return -1;
            }
            cur = cur->child[c];
        }
        
        return cur->isPath ? cur->value : -1;
    }
    
public:
    FileSystem() {
        root = new Trie();
    }
    
    bool createPath(string path, int value) {
        return insertPath(root, path, value);
    }
    
    int get(string path) {
        return getPathValue(root, path);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

// Solution 2: Using HashMaps

class FileSystem {
    unordered_map<string, int> paths;
public:
    FileSystem() {}
    
    bool createPath(string path, int value) {
        if(paths.find(path) != paths.end()) {
            return false;
        }
        
        int pos = path.find_last_of('/');
        
        if(pos == 0 || paths.find(path.substr(0, pos)) != paths.end()) {
            paths[path] = value;
            return true;
        }
        
        return false;
    }
    
    int get(string path) {
        if(paths.find(path) == paths.end()) {
            return -1;
        }
        return paths[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */