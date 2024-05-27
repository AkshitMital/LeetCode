class Solution {
private:
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>& upperLeftDiagonal, vector<int>& lowerLeftDiagonal, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(!leftRow[row] && !upperLeftDiagonal[n - 1 + col - row] && !lowerLeftDiagonal[row+ col]){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperLeftDiagonal[n - 1 + col - row] = 1;
                lowerLeftDiagonal[row + col] = 1;
                solve(col+1, board, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n);
                board[row][col] = '.';
                leftRow[row] = 0;
                upperLeftDiagonal[n - 1 + col - row] = 0;
                lowerLeftDiagonal[row+ col] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i = 0; i < n; i++){
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperLeftDiagonal(2*n-1, 0), lowerLeftDiagonal(2*n-1, 0);
        solve(0, board, ans, leftRow, upperLeftDiagonal, lowerLeftDiagonal, n);
        return ans;
    }
};