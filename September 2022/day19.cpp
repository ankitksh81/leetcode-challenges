/*
        Find Duplicate File in System
        https://leetcode.com/problems/find-duplicate-file-in-system/submissions/
*/

// Solution: Hashmap

class Solution {
    unordered_map<string, vector<string>> umap;
public:
    void getFiles(string &s) {
        vector<string> res;
        stringstream ss(s);
        
        string path = "", file = "", temp;
        
        while (getline(ss, temp, ' ')) {
            if (path == "") {
                path = temp;
            }
            else if (file == "") {
                string name = "";
                int i = 0;
                while (i < temp.length() && temp[i] != '(') {
                    name += temp[i];
                    i++;
                }
                i++;
                
                string content = "";
                while (i < temp.length() && temp[i] != ')') {
                    content += temp[i];
                    i++;
                }
                
                string filename = path + "/" + name;
                umap[content].push_back(filename);
                file = "";
            }
        }
    }
    
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        for (string &path : paths) {
            getFiles(path);
        }
        
        vector<vector<string>> res;
        for (auto it : umap) {
            if (it.second.size() < 2) continue;
            res.push_back(it.second);
        }
        
        return res;
    }
};
