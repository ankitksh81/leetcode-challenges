/*
    Design In-Memory File System
    https://leetcode.com/problems/design-in-memory-file-system/
*/

// Solution 1: Trie + Hashmap

struct Folder {
    unordered_map<string, Folder*> child;
    vector<string> files;
};

class FileSystem {
private:
    Folder *root;
    unordered_map<string, string> fileSystem;
    // function to get all the folders in the path
    vector<string> getPaths(string s) {
        vector<string> res;
        s += "/";
        
        size_t next, last = 1;
        while((next = s.find("/", last)) != string::npos) {
            string ss = s.substr(last, next - last);
            if(!ss.empty()) {
                res.push_back(ss);
            }
            last = next + 1;
        }
        return res;
    }
    
public:
    FileSystem() {
        root = new Folder();
    }
    
    vector<string> ls(string path) {
        // if path already exists in fileSystem
        if(fileSystem.count(path)) {
            return {
                path.substr(path.find_last_of('/') + 1)
            };
        }
        // get all folders in the path
        vector<string> levels = getPaths(path);
        Folder *cur = root;
        // traverse till the last folder in the path
        for(auto &level: levels) {
            cur = cur->child[level];
        }
        // get all files in sorted order from the cur folder
        set<string> tmp(cur->files.begin(), cur->files.end());
        // get all subfolders from the cur folder
        for(auto &x: cur->child) {
            tmp.insert(x.first);
        }
        
        vector<string> res;
        // copy name of folders & files to the vector
        for(auto &x: tmp) {
            res.push_back(x);
        }
        return res;
    }
    
    void mkdir(string path) {
        // get all the folders in the path
        vector<string> levels = getPaths(path);
        Folder *cur = root;
        for(auto &level: levels) {
            // if the folder doesn't exists, create it and move
            if(cur->child.find(level) == cur->child.end()) {
                cur->child[level] = new Folder();
            }
            cur = cur->child[level];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        // if file already exists, append the content
        if(fileSystem.count(filePath)) {
            fileSystem[filePath] += content;
            return;
        }
        
        // if file doesn't exists, create & write the content
        fileSystem[filePath] = content;
        vector<string> levels = getPaths(filePath);
        Folder *cur = root;
        
        // traverse till the last subfolder
        for(int i = 0; i < levels.size() - 1; i++) {
            cur = cur->child[levels[i]];
        }
        // create the file in cur folder
        cur->files.push_back(levels.back());
    }
    
    string readContentFromFile(string filePath) {
        return fileSystem[filePath];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */

// Solution 2:

class FileSystem {
private:
    class Node {
        protected:
            string name;
        public:
            virtual bool isDirectory() const = 0;
            Node(const string& name){
                this->name = name;
            }
            string getName() const {
                return name;
            }
            virtual vector<string> ls() = 0;
            map<string, Node*> next;
    };
    
    class File: public Node {
    private:
        string data;    
    public:
        File(const string& name) : Node(name) {}
        bool isDirectory() const override {
            return false;
        }
        vector<string> ls() override{
            return {name};
        }
        void append(const string& str) {
            data.append(str);
        }
        string read() const {
            return data;
        }
    };
    
    class Directory : public Node {
        public:
        Directory(const string& name):Node(name) {}
        bool isDirectory() const override {
            return true;
        }
        vector<string> ls() override {
            vector<string> result;
            for(const auto& entry: next) {
                result.push_back(entry.first);
            }
            return result;
        } 
    };
    Node* root;
public:
    FileSystem() {
        root = new Directory("");
    }
    
    vector<string> ls(string path) {
        vector<string> tokens = tokenize(path);
        Node* curr = root;
        for(const auto& token: tokens){
            curr = curr->next[token];
        }
        return curr->ls();
    }
    
    void mkdir(string path) {
        vector<string> tokens = tokenize(path);
        Node* curr = root;
        for(const auto& token: tokens) {
            if(curr->next.count(token) == 0) {
                curr->next[token] = new Directory(token);
            }
            curr = curr->next[token];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> tokens = tokenize(filePath);
        Node* curr = root;
        for(const auto& token : tokens) {
            if(curr->next.count(token) == 0) {
                curr->next[token] = new File(token);
            }
            curr = curr->next[token];
        }
        ((File*)curr)->append(content);
    }
    
    string readContentFromFile(string filePath) {
        vector<string> tokens = tokenize(filePath);
        Node* curr = root;
        for(const auto& token: tokens) {
            curr = curr->next[token];
        }
        return ((File*)curr)->read();
    }
    
    vector<string> tokenize(const string& path) {
        vector<string> result;
        int pos = 1;
        string token;
        while(pos< path.size()) {
            if(path[pos] == '/'){
                result.push_back(token);
                token.clear();
            } else {
                token.push_back(path[pos]);
            }
            ++pos;
        }
        if(token.size() > 0)
            result.push_back(token);
        return result;
    }
};