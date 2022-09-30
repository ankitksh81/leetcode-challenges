/*
	The Skyline Problem
	https://leetcode.com/problems/the-skyline-problem/description/
*/

// Solution 1: Multiset

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans, events;//event_x, building_id, +1/-1
        for (auto &i : buildings) {
            events.push_back({i[0], -i[2]});
            events.push_back({i[1], i[2]});
        }

        sort(events.begin(),events.end());
        
        multiset<int> leftwall = {0};
        int top = 0;
        
        for (auto &eve : events) {
            if(eve[1] < 0) {//insertion
                leftwall.insert(-eve[1]);
            }
            else{
                leftwall.erase(leftwall.find(eve[1]));
            }
            if(top != *leftwall.rbegin()) {
                ans.push_back({eve[0], top = *leftwall.rbegin()});
            }
        }

        return ans;
    }
};


// Solution 2: Union Find

struct UF {
    vector<int> root;
    
    UF(int n) : root(n) {
        iota(root.begin(), root.end(), 0);
    }

    int find(int x) {
        if (root[x] != x) return find(root[x]);
        return root[x];
    }

    void merge(int x, int y) {
        root[x] = root[y];
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(), [](auto &a, auto &b) {
            return a[2] > b[2];
        });

        set<int> edgeSet;

        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }

        vector<int> edges(edgeSet.begin(), edgeSet.end());
        int N = edges.size();

        unordered_map<int, int> edgeIndexMap;
        for (int i = 0; i < N; i++) {
            edgeIndexMap[edges[i]] = i;
        }

        UF edgeUf(N);
        vector<int> heights(N);

        for (auto building : buildings) {
            int leftEdge = building[0], rightEdge = building[1];
            int height = building[2];

            int leftIdx = edgeUf.find(edgeIndexMap[leftEdge]);
            int rightIdx = edgeIndexMap[rightEdge];

            while (leftIdx < rightIdx) {
                heights[leftIdx] = height;

                edgeUf.merge(leftIdx, rightIdx);
                leftIdx = edgeUf.find(++leftIdx);
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < N; i++) {
            if (i == 0 || heights[i] != heights[i - 1]) {
                result.push_back({edges[i], heights[i]});
            }
        }

        return result;
    }
};