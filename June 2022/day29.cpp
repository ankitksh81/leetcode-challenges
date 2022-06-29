/*
	Queue Reconstruction by Height
	https://leetcode.com/problems/queue-reconstruction-by-height/
*/

// Solution: Greedy + Sorting

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int N = people.size();
        vector<vector<int>> result;
        
        sort(begin(people), end(people), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
        });
        
        for (int i = 0; i < N; i++) {
            int pos = people[i][1];
            result.insert(result.begin() + pos, people[i]);
        }
        
        return result;
    }
};


// Solution 2: Binary Indexed Tree

class Solution {
    vector<int> BIT;
    int n;
public:
    void update(int x, int v){
        for(int i = x; i <= n; i += (i & -i)){
            BIT[i] += v;
        }
    }
    
    int getsum(int x){
        int sum = 0;
        for(int i = x; i > 0; i -= (i & -i)){
            sum += BIT[i];
        }
        
        return sum;
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        BIT = vector<int>(n+1, 0); //BIT[i+1] recorded the res[i] information because BIT[0] is not used.
        vector<vector<int>> res(n, vector<int>());
        
        for (int i = 2; i <= n; i++) update(i, 1);  // BIT[1] is the 0th empty position, so we didn't add 1
        sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2) {
            return (v1[0] != v2[0]) ? v1[0] < v2[0] : v1[1] > v2[1];
        });
        
        for (int i = 0; i < n; i++) {
            int l = 0, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (getsum(mid + 1) < people[i][1]) {
                    l = mid + 1;
                }// we need get the index mid empty information, but actually it's stored in BIT[mid+1]
                else {
                    r = mid;
                }
            }
            res[l] = people[i];
            update(l + 1, -1);
        }
        
        return res;
    }
};