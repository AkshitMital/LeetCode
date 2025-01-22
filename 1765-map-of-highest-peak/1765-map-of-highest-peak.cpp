class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, -1, 1};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [row, col] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol] == -1) {
                        ans[nrow][ncol] = ans[row][col] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }

        return ans;
    }
};