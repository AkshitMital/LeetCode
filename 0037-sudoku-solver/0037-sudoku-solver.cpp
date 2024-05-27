class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
            if (board[row][i] == ch) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int s) {

        if(s==81) return true;

        const int row = s / 9;
        const int col = s % 9;

        if (board[row][col] != '.') return solve(board, s + 1);

        if (board[row][col] == '.'){
            for (char c = '1'; c <= '9'; c++){
                if (isValid(board, row, col, c)) {
                    board[row][col] = c;
                    if (solve(board, s + 1)) return true;
                    board[row][col] = '.';
                }
            }
        }

        return false;

        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] == '.') {
        //             for (char ch = '1'; ch <= '9'; ch++) {
        //                 if (isValid(board, i, j, ch)) {
        //                     board[i][j] = ch;
        //                     if (solve(board)) return true;
        //                     board[i][j] = '.';
        //                 }
        //             }
        //             return false;
        //         }
        //     }
        // }
        // return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0);
    }
};
