// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3905/


// Solution 1:

class Solution {
public:
	bool solve(vector<vector<char>>& board, int i, int j) {
		if(i == 9 && j == 0) {
			return true;
		}
		if(board[i][j] != '.') {
			return solve(board, (j+1) == 9 ? i+1 : i, (j+1) == 9 ? 0 : j+1);
		}

		for(char num = '1'; num <= '9'; num++) {
			if(isValid(board, i, j, num)) {
				board[i][j] = num;
				if(solve(board, (j+1) == 9 ? i+1 : i, (j+1) == 9 ? 0 : j+1)) {
					return true;
				}
				board[i][j] = '.';
			}
		}
		return false;
	}

	bool isValid(vector<vector<char>>& board, int r, int c, int d) {
		int allrow = 3 * (r / 3);
		int allcol = 3 * (c / 3);

		for(int i = 0; i < 9; i++) {
			if(board[i][c] == d)
				return false;
			if(board[r][i] == d)
				return false;
			if(board[allrow + i / 3][allcol + i % 3] == d)
				return false;
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		solve(board, 0, 0);
	}
};


// Solution 2:

class Solution {
public:
	using MaskArr = array<bitset<9>, 9>;

	void solveSudoku(vector<vector<char>>& board) {
		MaskArr col_mask{};
		MaskArr row_mask{};
		MaskArr box_mask{};

		vector<pair<int, int>> points;

		for(int row = 0; row < 9; row++) {
			for(int col = 0; col < 9; col++) {
				char val = board[row][col];

				if(val != '.') {
					auto bit = val - '1';

					row_mask[row].set(bit, true);
					col_mask[col].set(bit, true);

					int box_idx = (3 * (row / 3)) + (col / 3);
					box_mask[box_idx].set(bit, true);
				}
				else {
					points.emplace_back(row, col);
				}
			}
		}

		solve(board, points, col_mask, row_mask, box_mask);
	}

	bool solve(vector<vector<char>>& board, vector<pair<int, int>>& points,
		MaskArr& col_mask, MaskArr& row_mask, MaskArr& box_mask) {

		if(points.empty()) {
			return false;
		}

		auto [row, col] = points.back();
		points.pop_back();

		for(int i = 0; i < 9; i++) {
			int box_idx = (3 * (row / 3)) + (col / 3);

			if (!col_mask[col].test(i) && !row_mask[row].test(i) && !box_mask[box_idx].test(i)) {
                row_mask[row].set(i, true);
                col_mask[col].set(i, true);
                box_mask[box_idx].set(i, true);

                board[row][col ] = ('1' + i);

                if (points.empty() || solve(board, points, col_mask, row_mask, box_mask)){ 
                    return true;
                }

                row_mask[row].set(i, false);
                col_mask[col].set(i, false);
                box_mask[box_idx].set(i, false);

                board[row][col] = '.';
            }
		}

		points.emplace_back(row, col);

		return false;
	}
};