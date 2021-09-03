// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3962/


// Solution 1:

// Jarvis Algorith (Convex hull)
class Solution {
	struct VectorHash {
		size_t operator()(const std::vector<int>& v) const {
			std::hash<int> hasher;
			size_t seed = 0;
			for (int i : v) {
				seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
			}
			return seed;
		}
	};
	using MySet = std::unordered_set<std::vector<int>, VectorHash>;
	
public:
	int orientation(vector<int> &p, vector<int> &q, vector<int> &r) {
		return (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1]);
	}
	
	bool inBetween(vector<int> &p, vector<int> &q, vector<int> &r) {
		bool a = q[0] >= p[0] && q[0] <= r[0] || q[0] <= p[0] && q[0] >= r[0];
		bool b = q[1] >= p[1] && q[1] <= r[1] || q[1] <= p[1] && q[1] >= r[1];
		
		return (a && b);
	}
	
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		vector<vector<int>> ans;
		int n = trees.size();
		MySet hull;
		if(n < 4) {
			for(vector<int> tree: trees) {
				hull.insert(tree);
			}
			for(auto it: hull) {
				ans.push_back(it);
			}
			return ans;
		}
		int left_most = 0;
		for(int i = 0; i < n; i++) {
			if(trees[i][0] < trees[left_most][0]) {
				left_most = i;
			}
		}
		int p = left_most;
		
		do {
			int q = (p + 1) % n;
			for(int i = 0; i < n; i++) {
				if(orientation(trees[p], trees[i], trees[q]) < 0) {
					q = i;
				}
			}
			
			for(int i = 0; i < n; i++) {
				if(i != p && i != q && orientation(trees[p], trees[i], trees[q]) == 0 && inBetween(trees[p], trees[i], trees[q])) {
					hull.insert(trees[i]);
				}
			}
			
			hull.insert(trees[q]);
			p = q;
		} while(p != left_most);
		
		for(auto it: hull) {
			ans.push_back(it);
		}
		
		return ans;
	}
};


// Solution 2:

class Solution {
public:
	typedef complex<int>C;
	struct point {
		int x;
		int y;
	};
	
	set<pair<int, int>> s, coll;
	
	int cross(point a, point b, point c) {
		int x1 = a.x - b.x;
		int y1 = a.y - b.y;
		int x2 = a.x - c.x;
		int y2 = a.y - c.y;
		int val = x1 * y2 - x2 * y1;
		return val;
	}
	
	bool dis(point a, point b, point c) {
		C x1 = {a.x, a.y};
		C x2 = {b.x, b.y};
		C x3 = {c.x, c.y};
		return (abs(x2 - x1) > abs(x3 - x1));
	}
	
	void compute(point p[], int n) {
		point start = p[0];
		for(int i = 0; i < n; i++) {
			if(p[i].x < start.x) {
				start=p[i];
			}
		}
		
		s.insert({start.x, start.y});
		point curr = start;
		
		while(true) {
			point next = p[0];
			for(int i = 1; i < n; i++) {
				if(curr.x == p[i].x and curr.y == p[i].y)
					continue;
				
				int val = cross(curr, next, p[i]);
				if(val > 0) {
					next = p[i];
					coll.clear();
				}
				else if(val == 0) {
					if(dis(curr, next, p[i])) {
						coll.insert({p[i].x, p[i].y});
					}
					else {
						coll.insert({next.x, next.y});
						next = p[i];
					}
				}
			}
			
			for(auto it: coll) {
				s.insert(it);
			}
			
			if(next.x == start.x and next.y == start.y)
				break;
			s.insert({next.x, next.y});
			curr = next;
		}
	}
	
	vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
		int n = trees.size();
		point p[n];
		for(int i = 0; i < n; i++) {
			int m = trees[i][0];
			int k = trees[i][1];
			p[i] = {m, k};
		}
		compute(p, n);
		vector<vector<int>> res;
		for(auto it: s){
			vector<int> temp = {it.first, it.second};
			res.push_back(temp);
		}
		
		return res;
	}
};