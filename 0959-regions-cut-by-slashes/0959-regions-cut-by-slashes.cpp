class Solution {
private:
    void dfs(vector<vector<int>>& matrix, int row, int col){
        int n = matrix.size();
        matrix[row][col] = 1;
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !matrix[nrow][ncol]){
                dfs(matrix, nrow, ncol);
            }
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> matrix(n*3, vector<int>(n*3, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3 + 2][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3][j*3 + 2] = 1;
                }
                if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3 + 1][j*3 + 1] = 1;
                    matrix[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n*3; i++){
            for(int j = 0; j < n*3; j++){
                if(!matrix[i][j]){
                    dfs(matrix, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};