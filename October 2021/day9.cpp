/*
    Word Search II
    https://leetcode.com/problems/word-search-ii/
*/

// Solution 1:

class Solution {
    struct Trie {
        bool isLeaf;
        unordered_map<char, Trie*> child;
        
        Trie(): isLeaf(false) {}
    };
    
    void insert(Trie* head, string &word) {
        Trie* cur = head;
        for(char c: word) {
            // if node does not exist, create new node
            if(cur->child.find(c) == cur->child.end()) {
                cur->child[c] = new Trie();
            }
            // go to the next node
            cur = cur->child[c];
        }
        // mark end of the word
        cur->isLeaf = true;
    }
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<string> ans;
public:
    bool isValid(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#') {
            return false;
        }
        return true;
    }
    
    void findWord(vector<vector<char>>& board, int i, int j, Trie* root, string &str) {
        char c = board[i][j];
        if(!root->child[c]) {
            return;
        }
        str.push_back(c);
        board[i][j] = '#';
        
        if(root->child[c]->isLeaf) {
            ans.push_back(str);
            root->child[c]->isLeaf = false;
        }
        
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(board, x, y)) {
                findWord(board, x, y, root->child[c], str);
            }
        }
        
        board[i][j] = c;
        str.pop_back();
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for(auto &word: words) {
            insert(root, word);
        }
        
        int m = board.size(), n = board[0].size();
        string str = "";
        ans.clear();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                findWord(board, i, j, root, str);
            }
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int m, int n, string word, int i, int j, int idx) {
        if(idx == -1)
            return true;
        if(i < 0 || j < 0 || i == m || j == n || board[i][j] == '#')
            return false;
        if(word[idx] != board[i][j])
            return false;
        char c = board[i][j];
        board[i][j] = '#';
        if(dfs(board, m, n, word, i, j + 1, idx-1) ||
            dfs(board, m, n, word, i + 1, j, idx-1) ||
            dfs(board, m, n, word, i, j - 1, idx-1) ||
            dfs(board, m, n, word, i - 1, j, idx-1)) {
            board[i][j] = c;
            return true;
        }
        board[i][j] = c;
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        set<char> st;
        
        for(auto &word: words) {
            int n = word.length();
            char ch = word[n-1];
            st.insert(ch);
        }
        
        map<char,vector<pair<int, int>>> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = board[i][j];
                if(st.find(ch) != st.end()){
                    mp[ch].push_back({i, j}); 
                }
            }
        }
        
        for(int k = 0; k < words.size(); k++){
            string s = words[k];
            char ch = s[s.length()-1];
            vector<pair<int, int>> v = mp[ch];
            for(int i = 0; i < v.size(); i++){
                int x = v[i].first;
                int y = v[i].second;
                if(dfs(board, m, n, s, x, y, s.length()-1)){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};