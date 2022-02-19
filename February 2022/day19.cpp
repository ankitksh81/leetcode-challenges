/*
	Minimize Deviation in Array
	https://leetcode.com/problems/minimize-deviation-in-array/
*/

// Solution 1: Pretreatment + Sorting + Sliding Window

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> possible;
        // pretreatment
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                int temp = nums[i];
                possible.push_back({temp, i});
                while (temp % 2 == 0) {
                    temp /= 2;
                    possible.push_back({temp, i});
                }
            } else {
                possible.push_back({nums[i], i});
                possible.push_back({nums[i] * 2, i});
            }
        }
        sort(possible.begin(), possible.end());
        // start sliding window
        int minDeviation = INT_MAX;
        int notIncluded = n;
        int currentStart = 0;
        vector<int> needInclude(n, 1);
        for (auto& current : possible) {
            int currentValue = current.first;
            int currentItem = current.second;
            needInclude[currentItem] -= 1;
            if (needInclude[currentItem] == 0) {
                notIncluded -= 1;
            }
            if (notIncluded == 0) {
                while (needInclude[possible[currentStart].second] < 0) {
                    needInclude[possible[currentStart].second] += 1;
                    currentStart += 1;
                }
                if (minDeviation >
                    currentValue - possible[currentStart].first) {
                    minDeviation = currentValue - possible[currentStart].first;
                }
                needInclude[possible[currentStart].second] += 1;
                currentStart += 1;
                notIncluded += 1;
            }
        }
        return minDeviation;
    }
};

// Solution 2: Priority Queue

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minimum = INT_MAX;
        priority_queue<int> evens;
        for(int &x: nums) {
            if(x & 1) {
                evens.push(x * 2);
                minimum = min(minimum, 2 * x);
            } else {
                evens.push(x);
                minimum = min(minimum, x);
            }
        }
        
        int minDev = INT_MAX;
        while(!evens.empty()) {
            int curValue = evens.top();
            evens.pop();
            minDev = min(minDev, curValue - minimum);
            if(curValue % 2 == 0) {
                evens.push(curValue / 2);
                minimum = min(minimum, curValue / 2);
            }
            else {
                break;
            }
        }
        return minDev;
    }
};