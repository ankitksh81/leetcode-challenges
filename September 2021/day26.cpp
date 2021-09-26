// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3988/


// Solution 1:

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        int row_counter = 0, col_counter = 0;

        for(int row = 0; row < n; row++) {
            row_counter += board[row][0] ? 1 : -1;

            for(int col = 0; col < n; col++) {
                if(row == 0) {
                    col_counter += board[row][col] ? 1 : -1;
                }

                if((board[row][0] ^ board[0][0]) ^ (board[row][col] ^ board[0][col])) {
                    return -1;
                }
            }
        }

        if(abs(row_counter) > 1 || abs(col_counter) > 1) {
            return -1;
        }

        int row_swap_cnt = 0, col_swap_cnt = 0, row0_cnt = 0, col0_cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                row_swap_cnt += board[i][0];
                col_swap_cnt += board[0][i];
            }

            row0_cnt += board[i][0] == 0;
            col0_cnt += board[0][i] == 0;
        }

        int odd_pos_cnt = n / 2;
        if(n & 1) {
            row_swap_cnt = row0_cnt == odd_pos_cnt ? row_swap_cnt : (odd_pos_cnt - row_swap_cnt);
            col_swap_cnt = col0_cnt == odd_pos_cnt ? col_swap_cnt : (odd_pos_cnt - col_swap_cnt);
        }
        else {
            row_swap_cnt = min(row_swap_cnt, odd_pos_cnt - row_swap_cnt);
            col_swap_cnt = min(col_swap_cnt, odd_pos_cnt - col_swap_cnt);
        }

        return row_swap_cnt + col_swap_cnt;
    }
};


// Solution 2:

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        if(board.empty()) {
            return -1;
        }
        int N = board.size(), rowOneCnt = 0, colOneCnt = 0, rowToMove = 0, colToMove = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j] == 1) {
                    return -1;
                }
            }
        }

        for(int i = 0; i < N; i++) {
            rowOneCnt += board[0][i];
            colOneCnt += board[i][0];
            if(board[i][0] == i % 2)
                rowToMove++;
            if(board[0][i] == i % 2)
                colToMove++;
        }

        if(rowOneCnt < N/2 || rowOneCnt > (N+1)/2) {
            return -1;
        }
        if(colOneCnt < N/2 || colOneCnt > (N+1)/2) {
            return -1;
        }

        if(N % 2 == 1) {
            if(colToMove % 2 == 1)
                colToMove = N - colToMove;
            if(rowToMove % 2 == 1)
                rowToMove = N - rowToMove;
        }
        else {
            colToMove = min(colToMove, N - colToMove);
            rowToMove = min(rowToMove, N - rowToMove);
        }
        return (colToMove + rowToMove)/2;
    }
};