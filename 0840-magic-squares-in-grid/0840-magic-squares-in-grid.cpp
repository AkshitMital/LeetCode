class Solution {
private:
    bool isMagical(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> st;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int num = grid[r + i][c + j];
                if(num < 1 || num > 9 || st.count(num)) return false;
                else st.insert(num);
            }
        }

        int Rsum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        if(grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] != Rsum) return false;
        if(grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2]!= Rsum) return false;
        if(grid[r][c] + grid[r+1][c] + grid[r+2][c]!= Rsum) return false;
        if(grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1]!= Rsum) return false;
        if(grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2]!= Rsum) return false;
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2]!= Rsum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]!= Rsum) return false;

        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int ans = 0;

        for(int i = 0; i < rows - 2; i++){
            for(int j = 0; j < cols - 2; j++){
                if(isMagical(grid, i, j)) ans++;
            }
        }

        return ans;
    }
};