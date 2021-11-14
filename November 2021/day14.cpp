/*
    Iterator for combination
    https://leetcode.com/problems/iterator-for-combination/
*/

// Solution:

class CombinationIterator {
private:
    vector<string> all;
    int ptr;
    
    void solve(string characters, int n, int pos, int len, string res) {
        if(len == 0) {
            all.push_back(res);
            return;
        }
        if(pos >= n) {
            return;
        }
        
        res += characters[pos];
        solve(characters, n, pos+1, len-1, res);
        res.pop_back();
        solve(characters, n, pos+1, len, res);
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        solve(characters, characters.size(), 0, combinationLength, "");
        ptr = 0;
    }
    
    string next() {
        return all[ptr++];
    }
    
    bool hasNext() {
        return ptr < all.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */