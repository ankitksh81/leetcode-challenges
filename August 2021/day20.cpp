// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3904/


// Solution:
class Solution {
	bool row[9][9] = {{false}}, col[9][9] = {{false}};
	bool box[9][9] = {{false}};
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] != '.') {
					int val = board[i][j] - '0';
					if(row[i][val-1] == true || col[j][val-1] == true) {
						return false;
					}

					int box_no = (i/3) * 3 + j / 3;
					if(box[box_no][val-1] == true) {
						return false;
					}

					row[i][val-1] = true;
					col[j][val-1] = true;
					box[box_no][val-1] = true;
				}
			}
		}
		return true;
	}
};