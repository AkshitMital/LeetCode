class Solution {
private:
    bool check(int row, int col, vector<vector<int>>& vis2, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int& m, int& n){
        vis2[row][col] = 1;

        bool isSubIsland = true;
        if(grid1[row][col] == 0) isSubIsland = false;

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && !vis2[nrow][ncol] && grid2[nrow][ncol] == 1){
                if(!check(nrow, ncol, vis2, grid1, grid2, m, n)) isSubIsland = false;
            }
        }

        return isSubIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<int>> vis2(m, vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis2[i][j] && grid2[i][j] == 1){
                    if(check(i, j, vis2, grid1, grid2, m, n)) ans++;
                }
            }
        }

        return ans;
    }
};