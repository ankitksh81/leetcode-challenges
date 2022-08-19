/*
	Split Array into Consecutive Subsequences
	https://leetcode.com/problems/split-array-into-consecutive-subsequences/
*/

// Solution 1: Greedy + Hashmap

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> sub, freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        for (int num : nums) {
            if (freq[num] == 0) {
                continue;
            }
            
            if (sub[num - 1] > 0) {
                sub[num - 1]--;
                sub[num]++;
            }
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                sub[num + 2]++;
                freq[num + 1]--;
                freq[num + 2]--;
            }
            else {
                return false;
            }
            freq[num]--;
        }
        
        return true;
    }
};


// Solution 2: Optimized Space

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        int n = nums.size();
        int start = 0;

        for (int i = 1; i < n; i++) {
            //Check possibility of a valid segment starting at index start and ending at index i - 1.
            if (nums[i] - nums[i - 1] > 1) {
                if (!isSegmentValid(nums, start, i - 1)) {
                    return false;
                }
                //Update the starting index of the next segment.
                start = i;
            }
        }
        //Check for the last segment
        return isSegmentValid(nums, start, n - 1);
    }
    
private:
    bool isSegmentValid(vector<int> &nums, int start, int end) {
        int frequency = 0;

        //lengthOneSubsequences holds count of subsequences of length 1.
        int lengthOneSubsequences = 0;

        //lengthTwoSubsequences holds count of subsequences of length 2.
        int lengthTwoSubsequences = 0;

        //totalNoOfSubsequences holds count of all subsequences.
        int totalNoOfSubsequences = 0;

        for (int i = start; i <= end; i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                frequency++;
            } else if (frequency < lengthOneSubsequences + lengthTwoSubsequences) {
                // If the frequency[i] is less than total number of subsequences ending with i - 1,
                // we do not have enough subsequences where we can put i.
                return false;
            } else {
                // Total number of subsequences of length 2 can be obtained by
                // adding i to subsequences of length 1 ending with i - 1.
                lengthTwoSubsequences = lengthOneSubsequences;
                lengthOneSubsequences = max(0, frequency - totalNoOfSubsequences);
                totalNoOfSubsequences = frequency;
                frequency = 1;
            }
        }
        // For the last element in the segment.
        lengthTwoSubsequences = lengthOneSubsequences;
        lengthOneSubsequences = max(0, frequency - totalNoOfSubsequences);
        // If there is no remaining subsequence of length one or two, we can return true. 
        // Otherwise, return false.
        return lengthOneSubsequences == 0 && lengthTwoSubsequences == 0;
    }
};