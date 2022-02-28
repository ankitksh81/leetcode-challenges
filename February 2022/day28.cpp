/*
	Summary Ranges
	https://leetcode.com/problems/summary-ranges/
*/

// Solution: Greedy

    class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            if(nums.empty()) {
                return {};
            }
            if(nums.size() == 1) {
                return {to_string(nums[0])};
            }
            vector<string> res;
            string range = to_string(nums[0]);
            int prev = 0;
            for(int i = 1; i < nums.size(); i++) {
                if(nums[i] != nums[i-1] + 1) {
                    if(i - 1 == prev) {
                        res.push_back(range);
                    }
                    else {
                        res.push_back(range + "->" + to_string(nums[i-1]));
                    }
                    range = to_string(nums[i]);
                    prev = i;
                }
            }
            if(range == to_string(nums.back())) {
                res.push_back(range);
            }
            else {
                res.push_back(range + "->" + to_string(nums.back()));
            }

            return res;
        }
    };	