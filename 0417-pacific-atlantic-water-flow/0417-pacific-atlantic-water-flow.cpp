class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<int>>& vis){
        int m = heights.size(), n = heights[0].size();
        vis[row][col] = 1;
        int delrow[4] = {0, -1, 0, 1};
        int delcol[4] = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && (heights[nrow][ncol] >= heights[row][col]))
            {
                dfs(nrow, ncol, heights, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n,0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));
        vector<vector<int>> ans;

        for(int c = 0; c < n; c++){
            dfs(0, c, heights, pacific);
            dfs(m-1, c, heights, atlantic);
        }

        for(int r = 0; r < m; r++){
            dfs(r, 0, heights, pacific);
            dfs(r, n-1, heights, atlantic);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};