/*
	Min Cost to Connect All Points
	https://leetcode.com/problems/min-cost-to-connect-all-points/
*/

// Solution 1: Minimum Spanning Tree - Kruskal's Algorithm

class UF {
public:
    vector<int> parent;
    vector<int> rank;
    	
    UF (int size) {
        parent = vector<int>(size);
        rank = vector<int>(size);
        
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int find (int a) {
        if (parent[a] != a) {
            return parent[a] = find(parent[a]);
        }
        
        return parent[a];
    }
    
    bool join (int a, int b) {
        a = find(a);
        b = find(b);
        
        if (a == b)  return false;
        
        if (rank[a] > rank[b])       parent[b] = a;
        else if (rank[b] > rank[a])  parent[a] = b;
        else {
            parent[a] = b;
            rank[b]++;
        }
        
        return true;
    }
};

struct Node {
    
    int u;
    int v;
    int w;
    
    Node(int u, int v, int w) : u(u), v(v), w(w) {}
    
    bool operator<(const Node& node) const {
        return w < node.w;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int size = points.size();
        vector<Node> edges;
        UF uf(size);
        
        for(int cur_node = 0; cur_node < size; cur_node++) {
            for(int next_node = cur_node + 1; next_node < size; next_node++) {
                
                int weight = abs(points[cur_node][0] - points[next_node][0]) +
                             abs(points[cur_node][1] - points[next_node][1]);
                
                edges.push_back({cur_node, next_node, weight});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int mstCost = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < edges.size() && edgesUsed < size - 1; i++) {
            
            int node1 = edges[i].u;
            int node2 = edges[i].v;
            int weight = edges[i].w;
            
            if (uf.join( node1, node2 )) {
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
};

// Solution 2: Minimum Spanning Tree - Prims Algorithm Optimized

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int size = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        vector<bool> inMst(size);
        vector<int> minDist(size, INT_MAX);
        minDist[0] = 0;
        
        while (edgesUsed < size) {
            int curMinEdge = INT_MAX;
            int curNode = -1;
            
            for (int node = 0; node < size; node++) {
                if (!inMst[node] && curMinEdge > minDist[node]) {
                    curMinEdge = minDist[node];
                    curNode = node;
                }
            }
            
            mstCost += curMinEdge;
            edgesUsed++;
            inMst[curNode] = true;
            
            for (int nextNode = 0; nextNode < size; nextNode++) {
                
                int weight = abs(points[curNode][0] - points[nextNode][0]) +
                        abs(points[curNode][1] - points[nextNode][1]);
                
                if (!inMst[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
};