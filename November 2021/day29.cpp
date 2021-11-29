/*  
    Accounts merge
    https://leetcode.com/problems/accounts-merge/
*/

// Solution 1: DFS

class Solution {
private:
    unordered_set<string> visited;
    unordered_map<string, vector<string>> adj;
public:
    void dfs(vector<string> &mergedAccount, string &email) {
        visited.insert(email);
        mergedAccount.push_back(email);
        
        for(auto &it: adj[email]) {
            if(visited.find(it) == visited.end()) {
                dfs(mergedAccount, it);
            }
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> mergedAccounts;
        int n = accounts.size();
        
        for(auto account: accounts) {
            string firstEmail = account[1];
            for(int i = 2; i < account.size(); i++) {
                string email = account[i];
                adj[firstEmail].push_back(email);
                adj[email].push_back(firstEmail);
            }
        }
        
        for(auto &account: accounts) {
            string name = account[0];
            string firstEmail = account[1];
            
            if(visited.find(firstEmail) == visited.end()) {
                vector<string> mergedAccount;
                mergedAccount.push_back(name);
                dfs(mergedAccount, firstEmail);
                
                sort(mergedAccount.begin() + 1, mergedAccount.end());
                mergedAccounts.push_back(mergedAccount);
            }
        }
        
        return mergedAccounts;
    }
};

// Solution 2: DSU

class Solution {
    struct DSU {
        vector<int> group;
        vector<int> size;
        
        DSU(int n) {
            group.resize(n);
            size.resize(n);
            
            for(int i = 0; i < n; i++) {
                group[i] = i;
                size[i] = 1;
            }
        }
        
        int findGroup(int x) {
            if(x == group[x]) {
                return x;
            }
            return group[x] = findGroup(group[x]);
        }
        
        void unionBySize(int a, int b) {
            int groupA = findGroup(a);
            int groupB = findGroup(b);
            
            if(groupA == groupB) {
                return;
            }
            
            if(size[groupA] >= size[groupB]) {
                size[groupA] += size[groupB];
                group[groupB] = groupA;
            }
            else {
                size[groupB] += size[groupA];
                group[groupA] = groupB;
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> mergedAccounts;
        DSU dsu(accounts.size());
        
        unordered_map<string, int> emailGroup;
        
        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                string name = accounts[i][0];
                
                if(emailGroup.find(email) == emailGroup.end()) {
                    emailGroup[email] = i;
                }
                else {
                    dsu.unionBySize(i, emailGroup[email]);
                }
            }
        }
        
        unordered_map<int, vector<string>> emails;
        
        for(auto it: emailGroup) {
            string email = it.first;
            int group = it.second;
            emails[dsu.findGroup(group)].push_back(email);
        }
        
        for(auto it: emails) {
            int group = it.first;
            vector<string> mergedAccount = {accounts[group][0]};
            mergedAccount.insert(mergedAccount.end(), it.second.begin(), it.second.end());
            sort(mergedAccount.begin() + 1, mergedAccount.end());
            mergedAccounts.push_back(mergedAccount);
        }
        
        return mergedAccounts;
    }
};










